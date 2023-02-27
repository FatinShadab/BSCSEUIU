public class Time{
    public int H, M, S;
    public boolean AM;

    public Time(){
        this.H = 12;
        this.M = this.S = 0;
        this.AM = true;
    }

    public Time(int H, int M){
        this.H = H-1;
        this.M = M;
        this.S = 0;
        this.AM = false;
    }

    public Time(int H, int M, int S){
      if (H > 12){
        this.H = H-12;
        this.AM = false;
      }
      this.M = M;
      this.S =  S;
    }
  
    public void add(int H, int M, int S, boolean state){
      if (state != this.AM){
        H += 12;
      }

      this.H +=H;
      this.M += M;
      this.S += S;
      this.refactorTime();
    }

    public void add(int H, int M, int S){
      this.add(H, M, S, this.AM);
    }
    
    public void add(int M, int S){
      this.add(0, M, S, this.AM);
    }
    
    public void add(Time t){
      this.add(t.H, t.M, t.S, t.AM);
    }
    
    public void refactorTime(){
      System.out.println("\tBefore Refector: H: "+this.H+" M:"+this.M+" S:"+this.S);
      while (this.S >= 60){
        this.M ++;
        this.S -= 60;
      }
      
      // can be improve here
      boolean increasedByM = false; 
      while (this.M >= 60){
        this.H++;
        this.M -= 60;
        increasedByM = true;
      }
      // can be improve here
      if (increasedByM && this.H == 12){
        this.AM = !this.AM;
      }
      
      while (H > 12){
        this.H = H-12;
        this.AM = !this.AM;
      }
      
      System.out.println("\tAfter Refector: H: "+this.H+" M:"+this.M+" S:"+this.S);
    }
    
    public void set(int H, int M, int S, boolean AM){
      this.AM = AM;
      this.H = this.M = this.S = 0;
      this.add(H, M, S, AM);
    }
    
    public void set(Time obj){
      this.set(obj.H, obj.M, obj.S, obj.AM);
    }

    @Override
    public String toString(){
      String timeNotation = this.H +":";
      
      if (this.M < 10){
        timeNotation += "0"+this.M+":";
      }else{
        timeNotation += this.M+":";
      }
      
      if (this.S < 10){
        timeNotation += "0"+this.S+" ";
      }else{
        timeNotation += this.S+" ";
      }
      
      if (this.AM){
          timeNotation += "AM";
        } else {
          timeNotation += "PM";
        }
        
        return timeNotation;
    }

}