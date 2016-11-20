mvt_word(im_srcZ, 2, 0, 0);
	
        CPaintDC dc(this);
        CRect r0;
        GetWindowRect(&ZRect );
        ScreenToClient(&ZRect);
        dc.GetClipBox(&r0);
        if ((ZRect & r0) != r0)
        {
            CDialog::OnPaint();
        }
        
        dc.SetStretchBltMode(COLORONCOLOR);
        dc.SetMapMode(MM_TEXT);
		
		bitm.FromHandle(m_bmpC);

		if(onlyonce==true){bitm.CreateCompatibleBitmap(&dc, ImageW, ImageH); onlyonce=false;}

		bitm.SetBitmapBits(ImageW * ImageH * 2 ,im_srcZ->pix);//*8 307200
	
		GetWindowRect(&ZRect );
		ScreenToClient(&ZRect);   
		CDC      tmp;
		tmp.CreateCompatibleDC(0);
		CBitmap *old = tmp.SelectObject(&bitm);//CBitmap::FromHandle(hBmp)
		BITMAP   bmp;
		::GetObject(bitm,sizeof(BITMAP),&bmp);
    
		int      w   = ZRect.right  - ZRect.left;
		int      h   = ZRect.bottom - ZRect.top;
    
		dc.BitBlt(ZRect.left,ZRect.top,w,h,&tmp,0,0,SRCCOPY);
		
		tmp.SelectObject(old);
		}