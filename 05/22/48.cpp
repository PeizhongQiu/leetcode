class Solution {
public:
    void _rotate(vector<vector<int>>& matrix, int startA, int startB, int length) {
        for(int i = 0; i < length - 1; ++i) {
            int temp = matrix[startA + i][startB];
            matrix[startA + i][startB] = matrix[startA + length - 1][startB + i];
            matrix[startA + length - 1][startB + i] = matrix[startA + length - 1 - i][startB + length - 1];
            matrix[startA + length - 1 - i][startB + length - 1] = matrix[startA][startB + length - 1 - i];
            matrix[startA][startB + length - 1 - i] = temp;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int i = 0; i < m / 2; ++i) {
            _rotate(matrix, i, i, m - 2 * i);
        }
    }
};