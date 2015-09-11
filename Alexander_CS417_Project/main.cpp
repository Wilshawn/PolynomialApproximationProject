#include <iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{   //declaring initial variables
	int  i, endpoint;
	int  n = 0;
	float a0,a1,b0,b1,sumx=0,sumy=0,sumxy=0,sumxx=0,
    sumx1=0,sumy1=0,sumxy1=0,sumxx1=0,
	sumx2=0,sumy2=0,sumxy2=0,sumxx2=0;
	ifstream myfile;

    //input number of x y values
	cout<<"Enter number of sample points ? ";
	cin >> n;
	int x[n], f[n];

    //open up file to get data
	myfile.open("data.txt");
	if (myfile.is_open())
    {
            //while (!myfile.eof())
            //{


                //store data in arrays, also calculates basis
                for(i=0; i<n; i++)
                {
                    myfile >> x[i] >> f[i];
                    sumx = sumx + x[i];
                    sumy = sumy + f[i];
                    sumxy = sumxy + (x[i]*f[i]);
                    sumxx = sumxx + (x[i]*x[i]);
                    //n = n+1;
                }

            //}
    }
    else {
        cout <<"Unable to open file" << endl;
        return 0;
    }

    myfile.close();
    myfile.clear();
	//clrscr();
	/*
	//test debug data, manually type in points
	cout<<"Enter number of sample points ? ";
	cin >> n;
	cout << "Enter all sample points: " <<endl;
	for(i=0;i<n;i++)
	{
		cin>>x[i]>>f[i];
		sumx+=x[i];
 		sumy+=f[i];
		sumxy+=x[i]*f[i];
		sumxx+=x[i]*x[i];
	}*/

	//division points, divide up data by division

	cout << endl;
	cout <<"Enter First Division Ending Point.(After how many points?)";
	cin >> endpoint;
	int sub1 = endpoint;
	int sub2 = n - endpoint;
	int sub1x[sub1], sub1y[sub1], sub2x[sub2], sub2y[sub2];
	//input data, store in another data for division 1
	for(i=0;i<endpoint;i++)
    {
        sub1x[i] = x[i];
        sub1y[i] = f[i];
        sumx1 = sumx1 + sub1x[i];
        sumy1 = sumy1 + sub1y[i];
        sumxy1 = sumxy1 + (sub1x[i]*sub1y[i]);
        sumxx1 = sumxx1 + (sub1x[i]*sub1x[i]);

    }
    //input data, create new array for division 2
    for(i=endpoint;i<n;i++)
    {
        sub2x[i] = x[i];
        sub2y[i] = f[i];
        sumx2 = sumx2 + sub2x[i];
        sumy2 = sumy2 + sub2y[i];
        sumxy2 = sumxy2 + (sub2x[i]*sub2y[i]);
        sumxx2 = sumxx2 + (sub2x[i]*sub2x[i]);

    }

    //this is test data, to make sure data is read and store properly

	/*for(i=0;i<n;i++)
  	  {
		cout << "X"<<i<<" equals: "<<x[i]<<endl;
		cout << "Y"<<i<<" equals: "<<f[i]<<endl;
		cout << endl;
		}
    //final calculations outputted.
      cout << "sum of x equals: "<<sumx<<endl;
      cout << "sum of y equals: "<<sumy<<endl;
      cout << "sum of xy equals: "<<sumxy<<endl;
      cout << "sum of x2 equals: "<<sumxx<<endl;
      cout << endl;

	  a0=(sumy*sumxx-sumx*sumxy)/(n*sumxx-sumx*sumx);
	  a1=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
	  cout << "The equation of the line is: "<<a0<<"+"<<a1<<"x"<<endl;*/

      //final equation and calculations displayed by division
	  cout << endl <<"DIVISION 1" << endl;
	  a0=(sumy1*sumxx1-sumx1*sumxy1)/(endpoint*sumxx1-sumx1*sumx1);
	  a1=(endpoint*sumxy1-sumx1*sumy1)/(endpoint*sumxx1-sumx1*sumx1);
	  cout << "The equation of the line is: "<<a0<<" + "<<a1<<"x"<<endl;

	  cout << endl << "DIVISION 2" << endl;
	  b0=(sumy2*sumxx2-sumx2*sumxy2)/(sub2*sumxx2-sumx2*sumx2);
	  b1=(sub2*sumxy2-sumx2*sumy2)/(sub2*sumxx2-sumx2*sumx2);
	  cout << "The equation of the line is: "<<b0<<" + "<<b1<<"x"<<endl;

//	  getch();
	 // system("pause");
	  return 0;
}
