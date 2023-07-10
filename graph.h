#include <iostream>
using namespace std;

class graph
{

  int nodes;
  int **m;

public:
  void alloc()
  {
    m = new int *[nodes];
    for (int i = 0; i < nodes; i++)
    {
      m[i] = new int[nodes];
    }
  }

  graph(int nodes)
  {
    this->nodes = nodes;
    alloc();
  }
  void add_edge(int node1, int node2)
  {
    m[node1][node2] = 1;
    m[node2][node1] = 1;
  }

  void show_matrix()
  {
    for (int i = 0; i < nodes; i++)
    {
      for (int j = 0; j < nodes; j++)
      {
        cout << m[i][j] << " ";
      }
      cout << endl;
    }
  }
  void complete()
  {
    for (int i = 0; i < nodes; i++)
    {
      for (int j = 0; j < nodes; j++)
      {
        if (m[i][j] == 0)
        {
          cout << "not a complete graph" << endl;
          return;
        }
      }
    }
    cout << "yes it is a complete graph" << endl;
  }

  void degree()
  {
    int in = 0;
    int out = 0;
    for (int i = 0; i < nodes; i++)
    {
      for (int j = 0; j < nodes; j++)
      {
        out += m[i][j];
      }
      cout << "out degree of node " << i << " is " << out << endl;
      out = 0;
    }

    for (int i = 0; i < nodes; i++)
    {
      for (int j = 0; j < nodes; j++)
      {
        in += m[j][i];
      }
      cout << "in degree of node " << i << " is " << in << endl;
      in = 0;
    }
  }

  ~graph(){
    for (int i =0;i<nodes;i++){
      delete[] m[i];
    }
    delete[] m;
  }
};

