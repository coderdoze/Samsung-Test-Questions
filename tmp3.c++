/*
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph)
and the edge weights are the probabilities of the doctor going from that division to other connected division but
the doctor stays 10mins at each division now there will be given time and had to find the division in which he will 
be staying by that time and is determined by finding division which has high probability.
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division in which he will be there,
the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling time is not considered \
and during that 10min at 10th min he will be in next division, so be careful
find the division with highest probability that doctor is in it after 10 min is div 3 and probability is 0.7.
After 9 minutes dr has yet to move to another division he is in div 1 and probability is 1.0. 
Forty minutes later the division with highest probabilty is 6 and probabilty is 0.77400

input 1 6 10 40 1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

output 1 6 0.774000

input 2 6 10 10 1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5


*/


//make a graph and traverse it considering the probability.
//solution from CareerCup
#include<iostream>
using namespace std;

void findans(double **graph, int nodes, int time, int start, double p, double answer[])
{
    
    if(time <= 0)
    {
        answer[start] += p;
        return;
    }

    for(int i=1;i<=nodes;i++)
        if(graph[start][i] != 0)
        {
            p *= graph[start][i];
            findans(graph, nodes, time-10 , i , p ,answer);
            p /= graph[start][i];
        }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int nodes,edges,time;
        cin>>nodes>>edges>>time;
        double **graph = new double*[nodes];
        for(int i=1;i<=nodes;i++)
        {
            graph[i] = new double[nodes];
            for(int j=1;j<=nodes;j++)
                graph[i][j] = 0;
        }

        for(int i=0;i<edges;i++)
        {   
            int start, end;
            double prob;
            cin>>start>>end>>prob;
            graph[start][end] = prob;
        }
        double answer[nodes] = {0.0};
        findans(graph, nodes, time, 1, 1.0, answer);
        double final_prob = -1; int final_div = 0;
        for(int i=1;i<=nodes;i++)
        {
            if(answer[i]>final_prob)
            {
                final_prob = answer[i];
                final_div = i;
            }
        }
        cout<<final_div<<" "<<final_prob<<endl;
    }
    return 0;
}