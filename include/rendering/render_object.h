//
// Created by jakub on 5/26/16.
//

#ifndef DUCK_RENDER_OBJECT_H
#define DUCK_RENDER_OBJECT_H

#include <object.h>
#include <glm/gtc/matrix_transform.hpp>
#include <mesh/mesh.h>

class RenderObject : public Object{
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scaleFactor;

    glm::mat4 Model;

    Mesh* mesh;

    void initVectors();
public:

    RenderObject(ObjectID id, std::string name,
                 Mesh* mesh);

    ~RenderObject();

    /*
     * Moves to position
     */
    void moveTo(const glm::vec3& position);

    /*
     * Moves by the position vector.
     * The position is added to current on
     */
    void move(const glm::vec3& position);

    /*
     * Rotates to given rotation vector
     */
    void rotateTo(const glm::vec3& rotate);

    /*
     * Rotates by the rotation vector.
     * The values are added to current one
     */
    void rotate(const glm::vec3& rotate);

    void scale(const glm::vec3& scale);

    const glm::vec3& getPosition();

    Mesh* getMesh();

    void render(const Program& program);
    void update();
};


#endif //DUCK_RENDER_OBJECT_H
