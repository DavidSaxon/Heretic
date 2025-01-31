#version 130

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

//-----------------------------------UNIFORM------------------------------------

// the model matrix
uniform mat4 u_modelMatrix;
// the view matrix
uniform mat4 u_viewMatrix;
// the model view matrix
uniform mat4 u_modelViewMatrix;
// the normal matrix
uniform mat3 u_normalMatrix;
// the model, view, projection matrix
uniform mat4 u_modelViewProjectionMatrix;
// the shadow matrix
uniform mat4 u_shadowMatrix;

//-----------------------------------VARYING------------------------------------

// the texture coords
varying vec2 v_texCoord;
// the normal
varying vec3 v_normal;
// the eye position
varying vec3 v_eyePos;
// the shadow co-ordinates
varying vec4 v_shadowCoord;
// colour multiplier
varying vec4 v_colourMul;


//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main()
{
    //set the texture coords
    v_texCoord = vec2( gl_MultiTexCoord0 );
    // transform the normal into eye space
    // v_normal = normalize( vec3( u_modelViewMatrix * vec4( gl_Normal, 0.0 ) ) );
    v_normal = normalize( u_normalMatrix * gl_Normal );
    // calculate the eye position
    v_eyePos = -vec3( u_modelViewMatrix * gl_Vertex );
    // calculate shadow co-ordinates
    v_shadowCoord = u_shadowMatrix * vec4( gl_Vertex.xyz, 1.0 );

    // constant real colour
    float dis = abs( distance( gl_Vertex.xyz, vec3( 0.0, 0.0, 0.0 ) ) );
    dis = clamp( dis, 0.0, 2.0 );
    if ( dis < 1.0 )
    {
        v_colourMul = vec4(
                pow( dis, 5.0 ),
                pow( dis, 4.0 ),
                1.0,
                1.0 );
    }
    else
    {
        dis -= 1.0f;
        v_colourMul = vec4( 1.0,
                            1.0 - ( dis * 4.0 ),
                            1.0 - ( dis * 4.0 ),
                            1.0 );
    }
    v_colourMul = clamp( v_colourMul, 0.0, 1.0 );

    //set the position
    gl_Position = u_modelViewProjectionMatrix * gl_Vertex;
}
