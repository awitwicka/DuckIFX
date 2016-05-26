#version 330 core

in vec3 Normal;
in vec3 FragPos;

out vec4 color;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

void main()
{
    vec3 norm = normalize(Normal);

    // ---- Ambient ----- //
    vec3 ambient = material.ambient * light.ambient;

    // ---- Diffuse ----- //
    vec3 lightDir = normalize(light.position - FragPos);
    float diffuseFactor = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = (diffuseFactor * material.diffuse) * light.diffuse;

    // ---- Specular----- //
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = material.specular * spec * light.specular;

    vec3 result = (ambient + diffuse + specular);
    color = vec4(result, 1.0f);
}