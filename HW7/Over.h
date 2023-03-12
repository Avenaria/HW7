#pragma once
#include <iostream>
#include <Windows.h>
#include <map>
using namespace std;

class Overcoat {
	char* type_; 
	char* brand_; 
	char* model_; 
	double price_; 
public:
	Overcoat() :Overcoat("", "", "", 0) {}
	Overcoat(const char*, const char*, const char*, double);
	
	~Overcoat() {};
	
	Overcoat(const Overcoat& other);
	
	Overcoat(Overcoat&& other);

	Overcoat& operator=(const Overcoat& other);
	
	Overcoat& operator=(Overcoat&& other);
	bool operator==(const Overcoat& other);
	bool operator!=(const Overcoat& other);
	bool operator>(const Overcoat& other);
	bool operator<(const Overcoat& other);
	friend ostream& operator<<(ostream& out, const Overcoat& other);
	friend void swap(Overcoat& l, Overcoat& r);
};
Overcoat::Overcoat(const char* type, const char* brand, const char* model, double price) {
	type_ = _strdup(type);
	brand_ = _strdup(brand);
	model_ = _strdup(model);
	price_ = price;
}
Overcoat::~Overcoat() {
	delete[]type_;
	delete[]brand_;
	delete[]model_;
}
Overcoat::Overcoat(const Overcoat& other) {
	type_ = _strdup(other.type_);
	brand_ = _strdup(other.brand_);
	model_ = _strdup(other.model_);
	price_ = other.price_;
}
Overcoat::Overcoat(Overcoat&& other) {
	type_ = other.type_;
	other.type_ = nullptr;
	brand_ = other.brand_;
	other.brand_ = nullptr;
	model_ = other.model_;
	other.model_ = nullptr;
	price_ = other.price_;
}
Overcoat& Overcoat::operator=(const Overcoat& other) {
	Overcoat tmp(other);
	swap(*this, tmp);
	return *this;
}
Overcoat& Overcoat::operator=(Overcoat&& other) {
	swap(*this, other);
	return *this;
}
bool Overcoat::operator==(const Overcoat& other) {
	map <char*, char*> MAP({ {type_, other.type_}, {brand_, other.brand_}, {model_, other.model_} });
	for (auto& i : MAP) {
		if (strlen(i.first) != strlen(i.second))
			return false;
		if (strcmp(i.first, i.second))
			return false;
	}
	if (price_ != other.price_)
		return false;
	return true;
}
bool Overcoat::operator!=(const Overcoat& other) {
	return !(operator == (other));
}
bool Overcoat::operator>(const Overcoat& other) {
	return price_ > other.price_;
}
bool Overcoat::operator<(const Overcoat& other) {
	return price_ < other.price_;
}
ostream& operator<<(ostream& out, const Overcoat& other) {
	out << "Òèï: " << other.type_ << ", Ìàðêà: " << other.brand_ <<
		", Ìîäåëü: " << other.model_ << ", Öåíà: " << other.price_;
	return out;
}
void swap(Overcoat& l, Overcoat& r) {
	using std::swap;
	swap(l.type_, r.type_);
	swap(l.brand_, r.brand_);
	swap(l.model_, r.model_);
	swap(l.price_, r.price_);
}