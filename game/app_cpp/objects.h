#ifndef OBJECTS_H_
#define OBJECTS_H_
#include "raylib.h"
#include <iostream>
#include <vector>

// to make more human-readable while writing functions
enum LogicState{
	LOGIC_OFF = 0,
	LOGIC_ON = 1,
};

class Object{
	public:
		Vector2 pos;
		virtual ~Object(){}

};


class Wire : public Object{
	public:
		Vector2 endPos;
		LogicState curLogicState;

		Wire(Vector2 pos, Vector2 endPos);
	
};

/*class SelfHostingConnection{
	public:
		Vector2 pos;
		vector<Wire> connectedWires;
		LogicState logicState;

		/// @brief Connection constructor
		/// @param pos 
		/// @param curLogicState 
		/// @param initWire wire on which a new connection will be introduced
		SelfHostingConnection(Vector2 pos, LogicState logicState, Wire initWire){
			this->pos = pos;
			this->logicState = logicState;
			connectedWires = vector<Wire>{initWire};
		}

		void add_wire(Wire wireToAdd){
			std::cout<<"\nadding wire to the existing connection\nconnection logic state: " << this->logicState;
			wireToAdd.curLogicState = this->logicState;
			connectedWires.push_back(wireToAdd);
		}

		void change_logic_state(LogicState logicState){
			this->logicState = logicState;
			for(int i = 0; i < this->connectedWires.size(); i++){
				connectedWires[i].curLogicState = logicState;
			}
		}
};*/

class Connection : public Object{
	public:
		std::vector<Wire> connectedWires;
		LogicState curLogicState;

		/// @brief Connection constructor
		/// @param pos 
		/// @param curLogicState 
		/// @param initWire wire on which a new connection will be introduced
		Connection(Vector2 pos, LogicState curLogicState, Wire initWire);

		void add_wire(Wire wireToAdd);

		void change_logic_state(LogicState logicState);

};
#endif