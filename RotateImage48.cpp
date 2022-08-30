#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
private:
    void diagRotate( vector< vector< int > > &matrix ){ // rotates with respect to main diagonal
        int n = matrix.size(  );
        for( int row = 0; row < n; row++ ){
            for( int col = 0; col <= row; col++ ){
                int c = matrix[ row ][ col ];
                matrix[ row ][ col ] = matrix[ col ][ row ];
                matrix[ col ][ row ] = c;
            }
        }
    }
    void yRotate( vector< vector< int > > &matrix ){ // rotates with respect to the Y-axis / mid-column
        int n = matrix.size(  );
        for( int col = 0; col < n / 2; col++ ){
            for( int row = 0; row < n; row++ ){
                int c = matrix[ row ][ col ];
                matrix[ row ][ col ] = matrix[ row ][ n - col - 1 ];
                matrix[ row ][ n - col - 1 ] = c;
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        diagRotate( matrix );
        yRotate( matrix );
    }
};
int main(){
    vector< vector< int > > matrix{ { 1, 2 }, { 3, 4 } };
    cout << "Input:" << endl;
    for( vector< int > row : matrix ){
        for(int col : row ) cout << col << ' ';
        cout << endl;
    }
    Solution sol = Solution(  );
    sol.rotate( matrix );
    cout << "Output:" << endl;
    for( vector< int > row : matrix ){
        for(int col : row ) cout << col << ' ';
        cout << endl;
    }
    return 0;
}