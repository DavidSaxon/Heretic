#include "Sun.hpp"

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Sun::init()
{
    // add the mesh
    omi::Mesh* sunMesh =
            omi::ResourceManager::getMesh( "sun_std", "", NULL );
    sunMesh->getMaterial().glow =
                    new omi::Glow( sunMesh->getMaterial().colour.xyz(), 1.0f );
    m_components.add( sunMesh );

    // add light
    omi::Transform* lightPos = new omi::Transform(
            "",
            glm::vec3(),
            glm::vec3(),
            glm::vec3( 1.0f, 1.0f, 1.0f )
    );
    m_components.add( lightPos );
    omi::PointLight* light = new omi::PointLight(
            "",
            lightPos,
            1.0f,
            glm::vec3( 1.0f, 1.0f, 0.9f ),
            0.2f,
            0.0001f,
            0.0006f
    );
    m_components.add( light );
};

void Sun::update()
{
};
