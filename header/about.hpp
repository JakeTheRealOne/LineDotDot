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
# include <QTextEdit>


extern string APPNAME, APPVERSION, APPAUTHOR, APPLICENSE;


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

  // #### Button actions: ####

  /**
   * @brief Show the legal informations
   * 
   */
  void showLegal();

  /**
   * @brief Hide the legal informations
   * 
   */
  void hideLegal();

private:
  // #### Attributes: ####

  QWidget mainBox, aboutBox, versionBox, nameBox, authorBox, buttonsBox, topBar, legalBox;
  QLabel appName = QLabel(QString::fromStdString(APPNAME)), appVersion = QLabel(QString::fromStdString(APPVERSION)), appAuthor = QLabel(QString::fromStdString(APPAUTHOR)), legalTitle = QLabel("Legal"), legalSubtitle = QLabel("This software follows the GPL3.0 license");
  QTextEdit legalText = QTextEdit(QString::fromStdString(APPLICENSE));
  QPushButton toGithub = QPushButton("Github page"), toWiki = QPushButton("Morse infos"), legalButton = QPushButton("Legal"), closeButton = QPushButton(""), gobackButton = QPushButton("");
  QVBoxLayout voidLayout, aboutLayout, mainLayout, buttonsLayout, legalLayout;
  QHBoxLayout versionLayout, nameLayout, authorLayout, topLayout;
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