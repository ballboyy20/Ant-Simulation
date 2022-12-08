#ifndef GRIDWIDGET_H
#define GRIDWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QBasicTimer>
#include <QRectF>
#include <QMouseEvent>
#include "world.h"
#include <vector>
#include "qevent.h"
#include <QStyleOption>
#include <QBrush>

class GridWidget : public QWidget
{
    Q_OBJECT
public:

    explicit GridWidget(World &world , QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void reset_world();

signals:

protected:
    int foodPenThickness{10};
    int antPenThickness{20};
    int colonyScaleValue{70};
    double foodSize{10};

    QPoint colonyLocation;
    QPoint lastPoint;

    QPen set_up_pheromone_pen(char color);

    void paintEvent(QPaintEvent *event) override;
    void draw_pheromones(QPainter& antPainter, const std::vector<Pheromone>& pheromones, char color);
    void draw_food(QPainter& antPainter, const std::vector<Food>&food);
    void draw_colony(QPainter& antPainter);
    void draw_ants(QPainter& antPainter,const std::vector<Ant*>&ants);
    void draw_ant_food(QPainter& antPainter,const std::vector<Ant*>&ants);
    void place_colony();

    void DrawWindowBackground(QPainter &antPainter, QPaintEvent *event);


    std::vector<double> gridAntXPosition;
    std::vector<double> gridAntYPosition;

    World &antWorld;

    QImage antImage{":myicons/ant.png"};
    QImage foodImage{":myicons/food.png"};
    QImage colonyImage{":myicons/antcolony.png"};

    QPixmap colony = QPixmap(":myicons/antcolony.png");
};

#endif // GRIDWIDGET_H
