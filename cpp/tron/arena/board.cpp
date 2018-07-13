#include <QtGui>
#include "board.h"

Board::Board(QWidget* parent)
    : QWidget(parent)
{
}

Board::~Board()
{

}

void Board::paintEvent(QPaintEvent* /*event*/)
{
    if (m_map.size() == 0)
    {
        return;
    }

    const int BOARD_WIDTH = m_map[0].size();
    const int BOARD_HEIGHT = m_map.size();

    int logicWidth = BOARD_WIDTH*Scale;
    int logicHeight = BOARD_HEIGHT*Scale;

    int w = width();
    int h = height();

    QPainter painter(this);

    QPoint point;
    if (w > h)
    {
        int wg = h*BOARD_WIDTH/BOARD_HEIGHT;
        if (wg <= w)
        {
            point = QPoint(wg, h);
        }
        else
        {
            point = QPoint(w, w*BOARD_HEIGHT/BOARD_WIDTH);
        }
    }
    else
    {
        int hg = w*BOARD_HEIGHT/BOARD_WIDTH;
        if (hg <= h)
        {
            point = QPoint(w, hg);
        }
        else
        {
            point = QPoint(h*BOARD_WIDTH/BOARD_HEIGHT, h);
        }
    }

    painter.setViewport((w-point.x())/2, (h-point.y())/2, point.x(), point.y());
    painter.setWindow(0, 0, logicWidth+Margin*2, logicHeight+Margin*2);

    for (int row = 0; row < m_map.size(); ++row)
    {
        for (int col = 0; col < m_map[row].size(); ++col)
        {
            drawSquare(painter, col, row, m_map[row][col].toLatin1());
        }
    }
}

void Board::drawSquare(QPainter& painter, int x, int y, char c)
{
    x *= Scale;
    y *= Scale;
    x += Margin;
    y += Margin;

    QColor color;
    switch (c)
    {
        case '#': color = QColor(0, 0, 0); break;
        case '1': color = QColor(0, 0, 255); break;
        case '2': color = QColor(255, 0, 0); break;
        case '3': color = QColor(0, 255, 0); break;
        case ' ': color = QColor(255, 255, 255); break;
    }

    painter.save();

    painter.fillRect(x+1, y+1, Scale-1, Scale-1, color);

    painter.restore();
}

void Board::draw(const QVector<QString>& map)
{
    m_map = map;
    update();
}
