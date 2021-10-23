#include "Data.h"
void Data::move(Animal& oblect) { }

std::ostream& operator << (std::ostream& output_map, Data data) {
	for (int i(0); i < data.m_size; i++) {
		for (int j(0); j < data.m_size; j++)
			output_map << data.map[i][j] << " ";
		output_map << "\n";
	}
	return output_map;
}