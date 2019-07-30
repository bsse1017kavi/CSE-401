#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int start = 0;
int end = 256;

int current;
int n;
int *req;

struct mem
{
    int pos;
    bool isreq;
    bool chk;
};

struct diff
{
    int d;
    bool chk;
};

int calcDiff(int tempc,diff *di)
{
    for(int i=0;i<n;i++)
    {
        di[i].d = abs(req[i]-tempc);
    }
}

int findMin(diff *di)
{
    int in = -1, min = 258;

    for(int i=0;i<n;i++)
    {
        if(!di[i].chk && min>=di[i].d)
        {
            min = di[i].d;
            in = i;
        }
    }

    return in;
}

void fifs()
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        q.push(req[i]);
    }

    cout << "FIFS: ";

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}

void sstf()
{
    int tempc = current;

    diff *di = new diff[n];

    for(int i=0;i<n;i++)
    {
        di[i].d = 0;
        di[i].chk = false;
    }

    cout << "SSTF: ";

    for(int i=0;i<n;i++)
    {
        calcDiff(tempc,di);

        int in = findMin(di);
        di[in].chk = true;

        tempc=req[in];
        cout << tempc << " ";
    }

    cout << endl;

    delete [] di;

}

void scan()
{
    int tempc=current;

    mem *list1 = new mem[end];

    for(int i=start;i<end;i++)
    {
        list1[i].pos = i;
        list1[i].isreq=false;
        list1[i].chk = false;
    }

    for(int i=0;i<n;i++)
    {
        list1[req[i]].isreq = true;
    }


    cout << "Scan: ";

    for(int i=start;i<end;i++)
    {
        if(tempc<=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    for(int i=end-1;i>=start;i--)
    {
        if(tempc>=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    cout << endl;

    delete [] list1;
}

void cscan()
{
    int tempc = current;
    mem *list1 = new mem[end];

    for(int i=start;i<end;i++)
    {
        list1[i].pos = i;
        list1[i].isreq=false;
        list1[i].chk = false;
    }

    for(int i=0;i<n;i++)
    {
        list1[req[i]].isreq = true;
    }

    cout << "CScan: ";

    for(int i=start;i<end;i++)
    {
        if(tempc<=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    tempc = start;

    for(int i=start;i<end;i++)
    {
        if(tempc<=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    cout << endl;

    delete [] list1;
}

void look()
{
    int tempc = current;
    mem *list1 = new mem[end];

    for(int i=start;i<end;i++)
    {
        list1[i].pos = i;
        list1[i].isreq=false;
        list1[i].chk = false;
    }

    for(int i=0;i<n;i++)
    {
        list1[req[i]].isreq = true;
    }


    int max = -256;

    for(int i=0;i<n;i++)
    {
        if(max<=req[i]) max = req[i];
    }

    cout << "Look: ";

    for(int i=tempc;i<=max;i++)
    {
        if(tempc<=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    int min = 256;

    for(int i=0;i<n;i++)
    {
        if(min>=req[i]) min = req[i];
    }

    for(int i=tempc;i>=min;i--)
    {
        if(tempc>=list1[i].pos && list1[i].isreq && !list1[i].chk)
        {
            cout << list1[i].pos << " ";
            tempc = list1[i].pos;
            list1[i].chk = true;
        }
    }

    cout << endl;

    delete [] list1;
}

int main(void)
{
    cin >> n;
    req = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> req[i];
    }

    cin >> current;

    cout << endl;

    fifs();
    sstf();
    scan();
    cscan();
    look();
}
