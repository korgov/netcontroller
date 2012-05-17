#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QtGui/QGraphicsView>
#include <QSet>
#include <QHash>
#include <QForeachContainer>

#include "../core/model/graph.h"

class GraphicNode;
class GraphicEdge;


class GraphWidget: public QGraphicsView {


Q_OBJECT;

public:
	GraphWidget(Graph *graphInfo, QWidget *parent = 0);

	void itemMoved();

	Graph getGraph();

public slots:
	void shuffle();
	void zoomIn();
	void zoomOut();
	void nodeClickedSlot(GraphicNode* clickedNode);

	void setWaitToAdd(bool val) { waitToAdd = val; }
	void setWaitToAddEdge(bool val) { waitToAddEdge = val; }


protected:
	void keyPressEvent(QKeyEvent *event);
	void timerEvent(QTimerEvent *event);
	void wheelEvent(QWheelEvent *event);
	void drawBackground(QPainter *painter, const QRectF &rect);

	void mousePressEvent(QMouseEvent *event);


	void scaleView(qreal scaleFactor);

private:
	int timerId;
	GraphicNode *centerNode;
	Graph* graphInfo;
	QSet<GraphicNode*> nodes;
	QSet<GraphicEdge*> edges;
	QHash<Node*, GraphicNode*> nodeInfoToGNode;

	GraphicNode* firstSelected;
	GraphicNode* secondSelected;

	bool waitToAdd;
	bool waitToAddEdge;


private:
	QGraphicsScene* initScene(Graph *graphInfo);
	GraphicNode* getGNode(Node * nodeInfo);
	void addNodes(QGraphicsScene* scene, const QSet<GraphicNode*> &set);
	void addEdges(QGraphicsScene* scene, const QSet<GraphicEdge*> &set);
	void processSelectedNodes();


};

#endif
