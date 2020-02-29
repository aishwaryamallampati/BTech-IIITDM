int height(int i,int size)
{
	int l,r;
	if(i>size)
	 return 0;
	else
	{
	 l=height(2*i,size);
	 r=height(((2*i)+1),size);
	 if(l>r)
	 {
	  l=l+1;
	  return l;
	 }
	 else
	 {
	  r=r+1;
	  return r;
	 }
	}
}
