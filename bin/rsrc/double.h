class double
{
	rd8 m_in;

	~double()
	{
	}

	double()
	{
	}

	double(double a)
	{
		mov esi,this
		mov8 [esi],[ebp+s_off a]
	}

	double(double& a)
	{
		mov edi,this
		mov esi,a
		mov8 [edi],[esi]
	}
	
	double(int a)
	{
		mov edi,this
		sub esp,8
		push a
		calle rf.c_itof8
		mov8 [edi],[esp]
		add esp,8
	}

	double(uint a)
	{
		rstr s(a)
		rf.sscanf(s.cstr,"%lf",&this)
	}

	int toint()
	{
		rbuf<char> buf(128)
		rf.sprintf8(buf.begin,"%.0lf",this)
		return rstr(buf.begin).toint
	}

	rstr torstr()
	{
		rstr ret(this)
		return ret
	}
	
	friend double operator neg(double a)
	{
		return 0.0-a;
	}

	operator=(double a)
	{
		mov esi,this
		mov8 [esi],[ebp+s_off a]
	}

	operator=(double& a)
	{
		mov edi,this
		mov esi,a
		mov8 [edi],[esi]
	}

	friend operator<->(double& a,double& b)
	{
		c=a
		a=b
		b=c
	}

	operator+=(double a)
	{
		mov esi,this
		_fadd8 [esi],a
	}

	operator-=(double a)
	{
		mov esi,this
		_fsub8 [esi],a
	}

	operator*=(double a)
	{
		mov esi,this
		_fmul8 [esi],a
	}
	
	operator/=(double a)
	{
		mov esi,this
		_fdiv8 [esi],a
	}

	friend double operator+(double a,double b) 
	{
		_fadd8 a,b
		mov8 s_ret,a
	}

	friend double operator-(double a,double b)
	{
		_fsub8 a,b
		mov8 s_ret,a
	}

	friend double operator*(double a,double b)
	{
		_fmul8 a,b
		mov8 s_ret,a
	}

	friend double operator/(double a,double b)
	{
		_fdiv8 a,b
		mov8 s_ret,a
	}

	friend bool operator<(double a,double b)
	{
		_fclsb8 a,b
		mov s_ret,ebx
	}

	friend bool operator<=(double a,double b)
	{
		return a<b||a==b;
	}

	friend bool operator==(double a,double b)
	{
		cesb a,b
		if (ebx)
		{
			cesb [ebp+(s_off a+4)],[ebp+(s_off b+4)]
		}
		mov s_ret,ebx
	}

	friend bool operator!=(double a,double b)
	{
		return !(a==b)
	}

	friend bool operator>(double a,double b)
	{
		_fclsb8 b,a
		mov s_ret,ebx
		//return b<a;
	}

	friend bool operator>=(double a,double b)
	{
		return a>b||a==b;
		//return b<=a;
	}
	
	double abs()
	{
		if this<0.0
			return 0.0-this
		return this
	}

	clear()
	{
		mov esi,this
		mov [esi],0
		mov [esi+4],0
	}

	bool empty()
	{
		return 0==this
	}

	print()
	{
		rf.print this
	}

	printl()
	{
		rf.printl this
	}
};