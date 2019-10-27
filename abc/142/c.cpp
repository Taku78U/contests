#include <bits/stdc++.h>

using namespace std;

struct Student
{
  int num; // 出席番号
  int n; // 人数

  Student(int inputted_num, int inputted_n)
  {
    num = inputted_num;
    n = inputted_n;
  }
  bool operator<(const Student &another) const
  {
    return n < another.n;//人数を比較
  };
  //2つのconstを付けないとコンパイルエラーになるので注意!!
};

int main(){
  int n;
  vector<Student> records;
  cin >> n;
  cin.ignore();
  int n_tmp;
  for(int i = 0; i < n; i++){
    cin >> n_tmp;
    records.push_back(Student(i, n_tmp));
  }
  cin.ignore();
  sort(records.begin(), records.end());

  for(int i = 0; i < n; i++){
    cout << records[i].num + 1 << " " << flush;
  }
  cout << endl;
  return 0;
}
