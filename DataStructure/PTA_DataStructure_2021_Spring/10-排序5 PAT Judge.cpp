#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INT_MAX = 0x7fffffff;

class Student{
private:
    vector<int>scores;
    
public:
    int id;
    int num_of_course;
    int total_score;
    int perfect_solved;
    
    Student(int n):id(INT_MAX),num_of_course(n),total_score(0),perfect_solved(0)
    {
        for(int i = 0;i<=num_of_course;++i)
        {
            scores.push_back(-1);
        }
    }
    
    void updateScore(const int &cid,const int &score);
    void updateScore(const vector<int>&full_scores);
    bool operator< (const Student &other)const;
    void Print();
};

void Student::updateScore(const int &cid,const int &score)
{
    scores[cid] = max(scores[cid],score);
}

void Student::updateScore(const vector<int>&full_scores)
{
    for(int i = 1;i<=num_of_course;++i)
    {
        if(scores[i]>0)
        {
            total_score+=scores[i];
            if(scores[i]==full_scores[i])
            {
                perfect_solved+=1;
            }
        }
    }
}

bool Student:: operator< (const Student &other)const
{
    if(total_score!=other.total_score)
    {
        return total_score>other.total_score;
    }
    if(perfect_solved!=other.perfect_solved)
    {
        return perfect_solved>other.perfect_solved;
    }
    return id<other.id;
}

void Student::Print()
{
    printf("%05d %d",id,total_score);
    for(int i = 1;i<=num_of_course;++i)
    {
        if(scores[i]>=0)
        {
            printf(" %d",scores[i]);
        }
        else
        {
            printf(" -");
        }
    }
    printf("\n");
}

int main()
{
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    vector<Student>students;
    vector<int>full_scores;
    
    // 初始化
    full_scores.push_back(0);
    for(int i = 0;i<M;++i)
    {
        int score = 0;
        scanf("%d",&score);
        full_scores.push_back(score);
    }
    
    for(int i = 0;i<=N;++i)
    {
        students.push_back(Student(M));
    }
    
    // 读入成绩
    int listNum = 0;
    for(int i = 0;i<K;++i)
    {
        int id,cid,score;
        scanf("%d %d %d",&id,&cid,&score);
        
        if(score==-1)
        {
            students[id].updateScore(cid,0);
            continue;
        }
        students[id].updateScore(cid,score);
        
        if(students[id].id==INT_MAX)
        {
            students[id].id=id;
            ++listNum;
        }
    }
    
    for(int i = 1;i<=N;++i)
    {
        students[i].updateScore(full_scores);
    }
    
    sort(students.begin()+1,students.end());
    
    int rank = 1;
    int prev = -1;
    
    for(int i = 1;i<=listNum;++i)
    {
        if(students[i].total_score!=prev)
        {
            prev = students[i].total_score;
            rank = i;
        }
        printf("%d ",rank);
        students[i].Print();
    }
    
    return 0;
}
