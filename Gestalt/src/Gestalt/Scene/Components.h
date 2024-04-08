#ifndef GESTALT_COMPONENTS_H
#define GESTALT_COMPONENTS_H

#include "Gestalt/src/Gestalt/pch.h"

namespace gestalt::components {

    struct Component {
        uint id;
    };

    struct Tag : Component {
        std::string tag;
    };

    struct Transform : Component {
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

        glm::mat4 getTransformMatrix() const {
            glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x),
                                                   glm::vec3(1.0f, 0.0f, 0.0f));
            rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
            rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
            glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);

            return translationMatrix * rotationMatrix * scaleMatrix;
        }

    };

    struct Mesh : Component {
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<uint> indices;
    };

    struct Material : Component {
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        float shininess;
    };

    struct Texture : Component {
        uint textureId;
        std::vector<glm::vec2> uvs; // UV per vertex
    };

    struct Camera : Component {
        float fov;
        float aspect;
        float near;
        float far;
        glm::vec3 target;
        glm::vec3 up;
        glm::vec3 position;
    };

    struct Light : Component {
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
    };

    // Physics

    struct RigidBody : Component {
        glm::vec3 velocity;
        glm::vec3 acceleration;
        glm::vec3 angularVelocity;
        glm::vec3 angularAcceleration;

        float restitution;
        float friction;
        float drag;

        glm::mat3 inertiaTensor;
        float mass;

        enum class BodyType {
            GhostStatic,
            Static,
            GhostKinematic,
            Kinematic,
            GhostDynamic,
            Dynamic
        } bodyType;
    };

    // Colliders

    struct Collider : Component {
        enum class Type {
            ConvexHull,
            OBB,
            Sphere,
            Capsule,
            Rectangle,
            Plane,
            Line,
            Ray
        } type;

        // Broad phase collision detection

        float broadPhaseRadius;

    };

    struct ConvexHullCollider : Collider {
        std::vector<glm::vec3> vertices;
        std::vector<glm::vec3> normals;
        std::vector<uint> indices;
        std::vector<glm::vec3> faceNormals;
        std::vector<uint> faceIndices;
    };

    struct OBBCollider : Collider {
        glm::vec3 min;
        glm::vec3 max;
    };

    struct SphereCollider : Collider {
        float radius;
    };

    struct CapsuleCollider : Collider {
        float radius;
        float height;
    };

    // 2D Colliders

    struct RectangleCollider : Collider {
        glm::vec3 position;
        glm::vec3 normal;
        float width;
        float height;
    };

    struct PlaneCollider : Collider {
        glm::vec3 position;
        glm::vec3 normal;
    };

    struct LineCollider : Collider {
        glm::vec3 start;
        glm::vec3 end;
    };

    struct RayCollider : Collider {
        glm::vec3 position;
        glm::vec3 direction;
    };
}

#endif //GESTALT_COMPONENTS_H
