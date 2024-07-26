/**
 * @file about.hpp
 * @author JakeTheRealOne
 * @brief Header file for About class
 * @version 0.1
 * @date 23-07-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# ifndef ABOUT_HPP
# define ABOUT_HPP


// #### Std inclusions: ####
# include <string>
using namespace std;

// #### Qt inclusions: ####
# include <QWidget>
# include <QLabel>
# include <QPushButton>
# include <QLayout>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QPainter>
# include <QPainterPath>
# include <QFont>
# include <QGraphicsDropShadowEffect>


extern string APPNAME, APPVERSION, APPAUTHOR;


/**
 * @brief About page of the application
 * 
 */
class About : public QWidget 
{
public:
  // #### Constructors: ####

  /**
  * @brief Construct a new About object
  * 
  */
  About();

  // #### Destructor: ####

  /**
  * @brief Destroy the About object
  * 
  */
  //~About() = default; // Removing because it leads to a Stack smashing

private:
  // #### Attributes: ####

  QWidget mainBox, versionBox, nameBox, authorBox, buttonsBox, topBar;
  QLabel appName = QLabel(QString::fromStdString(APPNAME)), appVersion = QLabel(QString::fromStdString(APPVERSION)), appAuthor = QLabel(QString::fromStdString(APPAUTHOR));
  QPushButton toGithub = QPushButton("Github page"), toWiki = QPushButton("I want to learn more"), closeButton = QPushButton("");
  QVBoxLayout mainLayout, buttonsLayout;
  QHBoxLayout versionLayout, nameLayout, authorLayout, topLayout, voidLayout;
  QFont versionFont = appVersion.font(), nameFont = appName.font();
  QGraphicsDropShadowEffect windowShadow;

  // #### Auxiliary methods: ####

  /**
   * @brief Build the children of the About page
   * 
   */
  void buildChildren();

  /**
   * @brief Build the layouts of the About page
   * 
   */
  void buildLayouts();

  /**
   * @brief Build the style of the About page
   * 
   */
  void buildStyle();

protected:
  /**
    * @brief Apply rounded corners
    * 
    * @param event 
    */
  void resizeEvent(QResizeEvent* event);
};


# endif