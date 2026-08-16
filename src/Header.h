#pragma once
#include<iostream>
#include<chrono>
#include<cassert>
#include<vector>


class Point2D {

private:
	int x{};
	int y{};

public:
	Point2D(int inX, int inY) {
		x = inX;
		y = inY;
	}

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	double distanceTo(const Point2D& point) const {
		double distance{};

		distance = std::sqrt(std::pow((point.getX() - x), 2) + std::pow((point.getY() - y), 2));

		return distance;
	};

};

class Rectangle {

private:
	int length{};
	int width{};

public:

	Rectangle(int l, int w) {
		length = l;
		width = w;
	}

	int area() {
		return length * width;
	}

	int perimeter() {
		return (length + width) * 2;
	}

	bool isSquare() {
		if (length = width)
			return true;
		else
			return false;
	}

};

class Timer {

private:
	std::chrono::time_point<std::chrono::steady_clock> beg{};
	
public:
	Timer() {
		beg = std::chrono::steady_clock::now();
		
	}
	
	void get_time_point() {
		std::cout << std::chrono::steady_clock::now().time_since_epoch();
	}

	double elapsed_seconds() const {
		return std::chrono::duration<double>(std::chrono::steady_clock::now() - beg).count(); ;
	}

};

class Fraction {

private:
	int numerator{};
	int denominator{};

public:
	Fraction(int num, int den) {
		
		//assert(den != 0 && "error : denominator can't be 0");
		
		numerator = num;
		denominator = (den != 0) ? den : 1;
	}
	void simplify() {
		if (numerator == 0)
			return;
		else {
			for (int i = denominator; i > 0; i--) {
				//int g = std::gcd(numerator, denominator); #include <numeric>
				if ((numerator % i == 0) && (denominator% i == 0)) {
					numerator /= i;
					denominator /= i;
					return;
				}
			}
		}
	}
	double to_double() const {
		return static_cast<double> (numerator) / denominator;
	}

	void print_frac() const {
		std::cout << numerator << " / " << denominator << '\n';
	}
};

class Inventory {
private:
	std::vector<std::string> items{};
	size_t max_capacity{};
public:
	Inventory(size_t capacity) : max_capacity(capacity) {
		//items.resize(max_capacity);
		//items = {};
	}

	bool add_item(const std::string& name) {
		if (items.size() < max_capacity) {
			items.push_back(name);
			return true;
		}
		else {
			std::cout << "Inventory full" << '\n';
			return false;
		}
	}

	size_t remaining_space() const {
		return max_capacity - items.size();
	}

	bool is_full() const {
			return items.size() == max_capacity;
	}

	void print_items() const {
		for (size_t i = 0; i < items.size(); i++)
			std::cout << items[i] << '\n';
	}
};

class Item {
private:
	int id{};
	std::string name{};
	size_t length{};
	size_t height{};

public:
	Item(int id, std::string n, size_t l, size_t h) : id(id), name(n), length(l), height(h) {
	}

	int get_id() const {
		return id;
	}

	size_t get_length() const {
		return length;
	}

	size_t get_height() const{
		return height;
	}
};

class Grid {
private:
	std::vector<std::vector<int>> grid{};
	size_t grid_length{};
	size_t grid_height{};
	std::vector<Item> placed_items{};
	

public:
	Grid(size_t l, size_t h): grid_length(l), grid_height(h){
		grid.resize(h);
		for (size_t i = 0; i < h; i++) {
			grid[i].resize(l, -1);
		}
	}

	void print_grid() const {
		for (size_t i = 0; i < grid.size(); i++) {
			for (size_t j = 0; j < grid[i].size(); j++) {
				std::cout << (grid[i][j] == -1 ? "| |" : "|#|");
			}
			std::cout << '\n';
		}
	}

	bool is_cell_free(int x, int y) const{
		if (x<0 || y<0 || x >= grid_length || y >= grid_height) {
			std::cout << "out of bound"<<'\n';
			//x >= grid_length compare toujours un int à un size_t
			return false;
		}
		else {
			return (grid[y][x] == -1);
		}
	}

	bool can_place_at(size_t x, size_t y, const Item& item) const{
		
		for (size_t i = x; i < (x + item.get_length()); i++) {
			for (size_t j = y; j < (y + item.get_height()); j++) {
				if (is_cell_free(i, j)) {
					continue;
				}
				else {
					std::cout << "Cannot be placed" << '\n';
					return false;
				}
			}
		}
		std::cout << "Can be placed" << '\n';
		return true;
	}

	bool place_item(int x, int y, const Item& item) {
		if (can_place_at(x, y, item)) {
			for (size_t i = x; i < (x + item.get_length()); i++) {
				for (size_t j = y; j < (y + item.get_height()); j++) {
					grid[j][i] = 0;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}
};

class IdManager {
private:
	std::vector<int> id_pool{};

public:
	IdManager() {
	}

	void init_ids() {
	}

	int find_slot_free() const{
		for (int i = 0; i < id_pool.size(); i++) {
			if (id_pool[i] == -1) {
				std::cout << "Free slot at : " << i << '\n';
				return i;
			}
		}
		std::cout << "No free slot" <<'\n';
		return -1;
	}
	int create_id() {
		int slot = find_slot_free();
		if (slot != -1) {
			id_pool[slot] = (slot);
			std::cout << "Slot created at : " << slot << '\n';
			return slot;
		}
		else {
			size_t new_id{ id_pool.size()};
			id_pool.push_back(new_id);
			std::cout << "New slot created at : " << new_id <<  '\n';
			return new_id;
		}
	}
	void remove_at_slot(int slot) {
		id_pool[slot] = -1;
		std::cout << "Slot freed at : " << slot << '\n';
	}

};