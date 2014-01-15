#include "sys_lib.h"

// write a class for the function

class RecursiveICA{

 private :

  int dataRows;
  int dataCols;
  double lmdinit;

 public :

  RecursiveICA(double lmdinitpara)
    {
      lmdinit=lmdinitpara;
    }


  void getDataRows(cv::Mat data, int &size)
  {
    size=data.rows;
  }

  void getDataCols(cv::Mat data, int & size)
  {
    size=data.cols;
  }

  void recursiveICA(cv::Mat datargb, cv::Mat & weights)
  {
    getDataRows(datargb, dataRows);
    getDataCols(datargb, dataCols);

    weights.create(dataRows, dataRows, CV_64F);
    randu(weights, Scalar(-1), Scalar(1));

    int iterate_num=0;

    for (int i=0;i<dataCols;i++)
      {
	iterate_num++;
	cv::Mat y=weights*datargb.col(i);

	cv::Mat tanh1, tanh2;
	exp(y,tanh1);
	exp(-1*y,tanh2);
	cv::Mat nonlin=(tanh1-tanh2)/(tanh1+tanh2);

	cv::Mat gn=weights.t() * nonlin;
	double lmd=lmdinit/pow((double)iterate_num, 0.7);
	weights=weights+(lmd/(1-lmd))*(weights-((y*gn.t())/(1+lmd*(nonlin.t()*y-1))));

	y.release();
	tanh1.release();
	tanh2.release();
	nonlin.release();
	gn.release();
      }
  }
};
