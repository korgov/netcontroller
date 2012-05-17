#ifndef GRAPHIC_NODE_H
#define GRAPHIC_NODE_H

#include <QGraphicsItem>
#include <QList>
#include "../core/model/node.h"

class GraphicEdge;
class GraphWidget;
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class GraphicNode: public QObject, public QGraphicsItem{

	Q_OBJECT;

public:
	GraphicNode(GraphWidget *graphWidget, Node *nodeInfo);

	void addEdge(GraphicEdge *edge);
	QList<GraphicEdge *> edges() const;

	enum {
		Type = UserType + 1
	};
	int type() const {
		return Type;
	}

	bool advance();

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	QList<GraphicEdge *> edgeList;
	QPointF newPos;
	GraphWidget *graph;
	Node* nodeInfo;

signals:
	void nodeClickedSignal(GraphicNode* clickedNode);
};

#endif
