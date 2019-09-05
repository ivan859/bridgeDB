#pragma once
#include <iostream>
#include <string.h>
#include <unordered_map>
#include "query_graph.hpp"
using namespace std;

class Interpreter
{
private:
	int parser_result = 0;
	bool is_inside_match;
	string query;
	unordered_map<string, void *> nodes;
	unordered_map<string, void *> matched_nodes;
	unordered_map<string, string> node_alias;
	unordered_map<string, void *> edges;
	unordered_map<string, void *> matcher_edges;
	unordered_map<string, string> edge_alias;
	query_graph* graph;
public:
	char* element = "1231313";
	Interpreter(string query);
	Interpreter(string query, string graph_name);
	void match(void);
	void return_clause(void);
	void create_node_id(string);
	void create_node_id(char *);
	void create_node_alias(string, string);
	void assign_node_value(string, void *);
	void create_edge_id(string);
	void create_edge_alias(string, string);
	void assign_edge_value(string, void *);
	void set_node_id_value(char*, void*);
	void set_node_id_value(string, void*);
	string get_query(void);
	void set_parse_result(int);
	int get_parse_result(void);
	// Getters
	unordered_map<string, void *> get_nodes_map(void);
	void *get_node_value(string);
	void *get_node_value_by_alias(string);
	unordered_map<string, void *> get_edges_map(void);
	void *get_edge_value(string);
	void *get_edge_value_by_alias(string);
	~Interpreter();
};
// #endif