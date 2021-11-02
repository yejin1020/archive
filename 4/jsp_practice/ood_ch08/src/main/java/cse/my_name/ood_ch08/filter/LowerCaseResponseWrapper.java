package cse.my_name.ood_ch08.filter;

import java.io.IOException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpServletResponseWrapper;

/**
 *
 * @author yejin
 */
public class LowerCaseResponseWrapper extends HttpServletResponseWrapper{

    public LowerCaseResponseWrapper(HttpServletResponse response) {
        super(response);
    }
    
    @Override
    public ServletOutputStream getOutputStream() throws IOException{
        LowerCaseOutputStream los = new LowerCaseOutputStream(
                                        getResponse().getOutputStream());
        return los;
    }
    
}
