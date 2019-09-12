#pragma once
#include<iostream>
#include"Edge.h"
using namespace std;

SerializableEdge::SerializableEdge() {
	this->objType = EDGE;
}

SerializableEdge Edge::getSerializable() {
	SerializableEdge serializable;
	serializable.id = this->id;
	serializable.setProperties(this->properties);
	//serializable.properties = this->properties;
	serializable.originNode = this->originNode->id;
	serializable.targetNode = this->targetNode->id;
	return serializable;
}

