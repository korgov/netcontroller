#ifndef NODE_H
#define NODE_H

#include <string>

#include "enums.h"
#include "position.h"

namespace core {
	class Node {
	public:
		Node() {};
		Node(unsigned long id, std::string name, std::string code, const Position &position)
			: id(id), name(name), code(code), position(position) {};
		Node(const Node& node)
				: id(node.id), name(node.name), code(node.code), position(node.position) {};

        virtual ~Node(){};

		unsigned long getId() const {return id;}
		std::string getName() const {return name;}
		std::string getCode() const {return code;}
		Position getPosition() const {return position;}

		void setId(unsigned long id) {this->id = id;}
		void setName(const std::string& name) {this->name = name;}
		void setCode(const std::string& code) {this->code = code;}
		void setPosition(const core::Position& pos) {position = pos;}


		Node& operator= (const Node& node);

		virtual NodeType getType() const =0;
//		virtual NodeType getExtInfo() = 0;


	protected:
		unsigned long id;
		std::string name;
		std::string code;
		Position position;
	};

	std::ostream& operator<< (std::ostream& os, const Node& n);
	std::istream& operator>> (std::istream& is, Node& n);
}

#endif
