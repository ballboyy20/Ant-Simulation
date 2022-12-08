#include "gridwidget.h"
#include <Eigen/Dense>
#include "antsimutils.h"


GridWidget::GridWidget(World &world, QWidget *parent): antWorld{world},QWidget{parent}
{
    this->place_colony();
}

void GridWidget::DrawWindowBackground(QPainter &antPainter, QPaintEvent *event)
{
    QBrush background = QBrush(QColor(0, 0, 0));
    antPainter.fillRect(event->rect(), background);
}

void GridWidget::draw_food(QPainter &antPainter, const std::vector<Food> &food)
{

    antPainter.save();

    for (int i{0}; i < food.size(); i++)
    {
        QRectF foodBox{food[i].get_x_coordinate() - foodSize, food[i].get_y_coordinate() - foodSize, foodSize, foodSize};
        antPainter.drawImage(foodBox, foodImage);
        antPainter.restore();
    }

    antPainter.restore();
}

void GridWidget::draw_ants(QPainter& antPainter, const std::vector<Ant *> &ants)
{
    antPainter.save();
    double antScaleValue{15};
    double halfAntScaleValue{antScaleValue * 0.5};

    for (int i{0}; i < antWorld.get_amount_ants(); i++)
    {
        QPointF antLocation{ants[i]->get_position()[0] ,ants[i]->get_position()[1]};
        Eigen::Vector2d orginalOrientation{{0.0,-1.0}};
        double rotationAngle{calculate_clockwise_alignment_angle_degrees(orginalOrientation, ants[i]->get_orientation())};
        antPainter.save();
        antPainter.translate(antLocation);
        antPainter.rotate(rotationAngle);
        antPainter.translate(-antLocation.x() + halfAntScaleValue, -antLocation.y() + halfAntScaleValue);
        QRectF antBox{antLocation.x()-antScaleValue, antLocation.y()-antScaleValue, antScaleValue, (antScaleValue)};

        antPainter.drawImage(antBox, antImage);
        antPainter.restore();
    }
    draw_ant_food(antPainter,ants);
    antPainter.restore();
}

void GridWidget::draw_ant_food(QPainter &antPainter, const std::vector<Ant *> &ants)
{
    double cargoShift{8.0};

    for (int i{0}; i < antWorld.get_amount_ants(); i++)
    {
        if (ants[i]->has_food())
        {
            QPointF cargoLocation{ants[i]->get_position()[0] + cargoShift, ants[i]->get_position()[1] - cargoShift};
            QRectF foodBox{cargoLocation.x()-foodSize, cargoLocation.y()-foodSize, foodSize, foodSize};
            antPainter.drawImage(foodBox, foodImage);
        }
    }
}

void GridWidget::draw_colony(QPainter& antPainter)
{
    antPainter.drawPixmap(colonyLocation, colony);
}

void GridWidget::draw_pheromones(QPainter &antPainter, const std::vector<Pheromone> &pheromones, char color)
{
    antPainter.save();
    antPainter.setPen(set_up_pheromone_pen(color));

    for (int i{0}; i < pheromones.size(); i++)
    {
        antPainter.drawPoint(pheromones[i].get_x_position(),pheromones[i].get_y_position());
    }
}

void GridWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QPoint position = event->pos();
    antWorld.add_sushi_roll(position.x(), position.y());
}

void GridWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->reset_world();
}


void GridWidget::paintEvent(QPaintEvent *event)
{

    QPainter antPainter(this);

    DrawWindowBackground(antPainter, event);

    draw_colony(antPainter);
    antWorld.update();
    draw_ants(antPainter,antWorld.get_ants());
    draw_food(antPainter, antWorld.get_food());
    draw_pheromones(antPainter,antWorld.get_home_pheromones(),'g');
    draw_pheromones(antPainter, antWorld.get_food_pheromones(),'b');
}

QPen GridWidget::set_up_pheromone_pen(char color)
{
    QPen pheromonePen;
    pheromonePen.setWidth(2);
    if (color == 'g')
    {
        pheromonePen.setColor(Qt::green);
    }
    else if (color == 'b')
    {
        pheromonePen.setColor(Qt::blue);
    }
    else
    {
        pheromonePen.setColor(Qt::red);
    }
    return pheromonePen;
}

void GridWidget::place_colony()
{
    colonyLocation.setX(antWorld.get_world_size()/2 - colonyScaleValue/2);
    colonyLocation.setY(antWorld.get_world_size()/2 - colonyScaleValue/2);
    colony = colony.scaled(colonyScaleValue,colonyScaleValue);
}

void GridWidget::reset_world()
{
    antWorld.reset();
}
