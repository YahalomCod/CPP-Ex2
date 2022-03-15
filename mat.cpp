#include "mat.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
#include <vector>
namespace ariel
{
	typedef vector< vector<int> > Matrix;
	/*
	this function build the frame of the matrix first+last row and first+last collumn
	*/
	void frame(Matrix& m, int ite, int k){
		int row=m.size();
		int col=m[0].size();
		for(int i=ite; i<row-ite; i++) {
			m[i][ite] = k;
			m[i][col - ite - 1] = k;
		}
		for(int i=ite; i<col-ite; i++) {
			m[ite][i] = k;
			m[row - ite - 1][i] = k;}
		}
	/*
	this function builds the wanted string for mat function to return by using the matrix built before
	1 - a
	0 - b 
	*/
	string build(Matrix& m, char a, char b){
		int row=m.size();
		int col=m[0].size();
		string ans;
		for (size_t i = 0; i < row; i++){
			for (size_t j = 0; j < col; j++){
				if(m[i][j] == 1){
					ans += a;}
				else{
					ans += b;}
			}
		if(i != row - 1){
			ans += '\n';}			
			}
		return ans;
	}
	//returns minimun between two numbers
	int min(int x, int y){
		if(x<y){
			return x;}
		return y;
	}
	/*
	this function builds and retruns a string that represent a carpet, get the size of the carpet and the pattern
	example input: 
		9 7 @ -
	return:
		@@@@@@@@@
		@-------@
		@-@@@@@-@
		@-@---@-@
		@-@@@@@-@
		@-------@
		@@@@@@@@@
	*/
	string mat(int col, int row, char a, char b){
		if(col%2 == 0 || row%2 == 0){
			throw std :: invalid_argument("Integer arguments most be odd numbers!");
		}
		if(col <= 0 || row <= 0){
				throw std :: invalid_argument("Integer arguments mmust be positive!");
			}
		if(a < '!' || b < '!' || a > '~' || b > '~'){
				throw std :: invalid_argument("ASCII value of chars needs to be between 33-126");
			}
		Matrix n(row ,vector<int>(col,0));
		//iterate min(col,row)/2 + 1 = number of frame inside the matrix
		for (int i = 0; i < min(col,row)/2 + 1; i++) {
			frame(n, i, i%2 + 1);}
		return build(n, a, b);
	}
}
