/**
 * @file gui_wrapper.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief Header file for the GuiWrapper class
 * @version 0.1
 * @date 24-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef GUI_WRAPPER_HPP
# define GUI_WRAPPER_HPP


// #### Qt inclusions: ####
# include <QWidget>
# include <QGraphicsDropShadowEffect>
# include <QHBoxLayout>
# include <QPainter>

// #### Internal inclusions: ####
# include "../header/gui.hpp"


// #### Std inclusions: ####
# include <iostream>
using namespace std;

/**
 * @brief Widget that englobes the GUI (adding shadow to the content)
 * 
 */
class GuiWrapper : public QWidget
{
public:
  // #### Construtors: ####

  /**
   * @brief Construct a new Gui Wrapper object
   * 
   */
  GuiWrapper();

  // #### Destructor: ####

  /**
   * @brief Destroy the Gui Wrapper object
   * 
   */
  ~GuiWrapper() = default;

private:
  // #### Attributes: ####
  GUI guiWidget;
  QHBoxLayout mainLayout;
  QGraphicsDropShadowEffect *windowShadow = new QGraphicsDropShadowEffect;

  // #### Auxiliary methods: ####

  /**
   * @brief Build the layouts of the Gui wrapper
   * 
   */
  void buildLayouts();

  /**
   * @brief Build the shadow of the GUI
   * 
   */
  void buildShadow();

  /**
   * @brief Build the style of the Gui wrapper
   * 
   */
  void buildStyle();

protected:

  /**
   * @brief Apply rounded corners to the Gui
   * 
   */
  void paintEvent(QPaintEvent *);
} ;


# endif