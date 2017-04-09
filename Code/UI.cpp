#include "UI.h"
//#include "Game.h"
#include <QGraphicsScene>
#include <QGraphicsView>

UI::UI() : QObject(), QGraphicsRectItem()
{
    rectUI = new QGraphicsRectItem(0, 0, 600, 50);
    rectUI->setBrush(QBrush(QColor(80, 80, 80, 255)));
    //scene()->addItem(rectUI);


    score = 55550;
    scoreString = std::to_string(score);
    scoreBoard = new QGraphicsTextItem(QString::fromStdString(scoreString));
    //scoreBoard->setPlainText(QString::fromStdString(score));
    scoreBoard->setDefaultTextColor(Qt::white);
    scoreBoard->setPos(20, 13);
    scoreBoard->setFont(QFont("monospace", 20));
    //scene()->addItem(scoreBoard);
}
