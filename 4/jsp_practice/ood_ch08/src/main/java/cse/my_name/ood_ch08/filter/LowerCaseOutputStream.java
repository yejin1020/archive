package cse.my_name.ood_ch08.filter;

import java.io.IOException;
import javax.servlet.ServletOutputStream;
import javax.servlet.WriteListener;

public class LowerCaseOutputStream extends ServletOutputStream {
    
    private ServletOutputStream mSos = null;

    public LowerCaseOutputStream(ServletOutputStream sos) {
        mSos = sos;
    }
    
    @Override
    public void write(int b) throws IOException{
        int c = (b == -1)?b: Character.toLowerCase(b);
        mSos.write(c);
    }
    
    @Override
    public boolean isReady(){
        throw new UnsupportedOperationException("Not supported yet");
    }
    
    public void setWriteListener(WriteListener writeListener){
        throw new UnsupportedOperationException("Not supported yet");
    }
}
