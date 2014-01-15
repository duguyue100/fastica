// Author: Hu Yuhuang (ARLAB)
// Data: 20140114
// Contact: duguyue100@gmail.com

#include "sys_lib.h"
#include "recursive_ica.h"

int main(void)
{
  RecursiveICA *ica=new RecursiveICA(0.995);
  Mat frame;
  frame=Mat::ones(3,3,CV_64F)*100;

  cv::Mat weights;
  ica->recursiveICA(frame, weights);

  cout << weights << endl;

  cout << frame << endl;
  cout << "hello" << endl;
  return 0;
}
