int Sum(int low, int high)
{
  int sumval=0;
  if(high>=low)
  {
  	for(int i=low;i<=high;i=i+1)
   	{
    		 sumval+=i;
   	} 
  }
 return sumval;
}
