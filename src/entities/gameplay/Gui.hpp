#ifndef HERETIC_ENTITIES_GAMEPLAY_GUI_HPP_
#   define HERETIC_ENTITIES_GAMEPLAY_GUI_HPP_

#include "src/omicron/entity/Entity.hpp"

class Gui : public omi::Entity
{
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    /** Sets whether the gui is visible or not */
    void setVisible( bool state );

    void setFunc1( const std::string& func1 );

    void setFunc2( const std::string& func2 );

    void setPower( float power );

    void setDistance( float distance );

    void setReload( float reload );

    void boostFunc1();

    void boostFunc2();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    omi::Sprite* m_targetSprite;

    // the transform of the function boxes
    omi::Transform* m_funcPos;
    // the function box sprites
    omi::Sprite* m_funcBoxSprite1;
    omi::Sprite* m_funcBoxSprite2;
    // the text of the functions
    omi::Text* m_funcText1;
    omi::Text* m_funcText2;

    // the transform of the distance multipliers
    omi::Transform* m_mulPos;
    // the power text
    omi::Text* m_powerText;
    // the distance text
    omi::Text* m_distanceText;

    // reload bar
    omi::Transform* m_reloadScale;
    omi::Sprite* m_reloadBackSprite;
    omi::Sprite* m_reloadFrontSprite;

    float m_func1Boost;
    float m_func2Boost;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void initComponents();

};

#endif
