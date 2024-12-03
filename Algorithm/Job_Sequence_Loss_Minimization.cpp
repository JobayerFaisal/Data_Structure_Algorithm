#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;      // Job ID
    double rate; // Loss rate (Li / Ti)
};

bool compareJobs(const Job &a, const Job &b)
{
    return a.rate > b.rate;
}

int main()
{
    vector<int> L = {3, 1, 2, 4};    // Loss per day
    vector<int> T = {4, 1000, 2, 5}; // Time required to complete each job
    int n = L.size();

    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i)
    {
        jobs[i].id = i + 1;
        jobs[i].rate = (double)L[i] / T[i];
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    cout << "Job sequence for minimize the loss is : ";
    for (const auto &job : jobs)
    {
        cout << job.id << ", ";
    }
    cout << endl;

    return 0;
}
