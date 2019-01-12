#pragma once

#include <array>
#include <vector>
#include <map>
#include <tuple>
#include <ostream>
#include <iostream>
#include <cmath>
#include <limits>

using std::cout;
using std::endl;
using std::array;
using std::vector;
using std::map;
using std::tuple;
using std::ostream;

template<class T1, class T2>
ostream& operator <<(ostream& os, const tuple<T1, T2>& s) {
	os << "{" << std::get<0>(s) << ", " << std::get<1>(s) << "}";
	return os;
}

template<class T>
ostream& operator <<(ostream& os, const vector<T>& s) {
	os << "[";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "]";
}

template<class T, size_t Size>
ostream& operator <<(ostream& os, const array<T, Size>& s) {
	os << "[";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "]";
}

template<class TKey, class TValue>
ostream& operator <<(ostream& os, const map<TKey, TValue>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << "(" << x.first << "; " << x.second << ")";
	}
	return os << "}";
}

void assert_equals(bool actual, bool expected) {
	if ( actual != expected ) {
		cout << "Assert: failed!" << endl;
		exit(1);
	}
	cout << "Assert: passed." << endl;
}

template<class T>
void assert_equals(const vector<T>& actual, const vector<T>& expected) {
	if ( actual.size() != expected.size() ) {
		cout << "Assert: failed!" << endl;
		cout << actual << endl;
		cout << "!=" << endl;
		cout << expected << endl;
		exit(1);
	}
	for ( size_t i = 0; i < actual.size(); i++ ) {
		if ( actual[i] != expected[i] ) {
			cout << "Assert: failed!" << endl;
			cout << actual << endl;
			cout << "!=" << endl;
			cout << expected << endl;
			exit(1);
		}
	}
	cout << "Assert: passed." << endl;
	cout << actual << endl;
	cout << "==" << endl;
	cout << expected << endl;
}

template<class T, size_t Size>
void assert_equals(const array<T, Size>& actual, const array<T, Size>& expected) {
	if ( actual.size() != expected.size() ) {
		cout << "Assert: failed!" << endl;
		cout << actual << endl;
		cout << "!=" << endl;
		cout << expected << endl;
		exit(1);
	}
	for ( size_t i = 0; i < actual.size(); i++ ) {
		if ( actual[i] != expected[i] ) {
			cout << "Assert: failed!" << endl;
			cout << actual << endl;
			cout << "!=" << endl;
			cout << expected << endl;
			exit(1);
		}
	}
	cout << "Assert: passed." << endl;
	cout << actual << endl;
	cout << "==" << endl;
	cout << expected << endl;
}

struct Point {
	int x;
	int y;
};

double get_distance(const Point p1, const Point p2) {
	return std::hypot(p1.x - p2.x, p1.y - p2.y);
}
