/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch08.filter;

import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.StringTokenizer;
import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;

/**
 *
 * @author yejin
 */
public class FileFilter implements Filter {
    
    private static final boolean debug = true;

    private FilterConfig filterConfig = null;
    
    public FileFilter() {
    }    
    
    private boolean doBeforeProcessing(ServletRequest request, ServletResponse response)
            throws IOException, ServletException {
        boolean status = true;
        request.setCharacterEncoding("UTF-8");
        if (debug) {
            log("FileFilter:DoBeforeProcessing");
        }
        
        HttpServletRequest httpReq = (HttpServletRequest) request;
        String fileName = httpReq.getParameter("file_name");
        StringTokenizer st = new StringTokenizer(fileName,".");
        String lastToken = null;
        while(st.hasMoreTokens()){
            lastToken = st.nextToken();
        }
        
        if(!lastToken.equals("txt")){
            
            response.setCharacterEncoding("UTF-8");
            PrintWriter out = response.getWriter();
            out.println("<html>");
            out.println("<head>");
            out.println(" <meta http-equiv= \"Content-Type\" "
                    + "content= \"text/html; charset=UTF-8\">");
            out.println("<title> 부적절한 파일 포멧 </title>");
            out.println("</head>");
            out.println("\"txt\" 형태가 아닌 파일을 선택하여 " 
                    + "내려받기가 거부되었습니다. <br/>");
            out.println("(파일명:" + fileName + ")");
            out.println("</html>");
            out.close();
            status = false;
        }
       
      return status;
    }    
    
    private void doAfterProcessing(ServletRequest request, ServletResponse response)
            throws IOException, ServletException {
        if (debug) {
            log("FileFilter:DoAfterProcessing");
        }
    }

    public void doFilter(ServletRequest request, ServletResponse response,
            FilterChain chain)
            throws IOException, ServletException {
        
        if(debug) {
            log("FileFilter:doFilter()");
        }
        
        boolean status = doBeforeProcessing(request, response);
        
        Throwable problem = null;
        try {
            if( status == true)
            chain.doFilter(request, response);
        } catch (Throwable t) {
       
            //problem = t;
            t.printStackTrace();
        }
        
        doAfterProcessing(request, response);

        if (problem != null) {
            if (problem instanceof ServletException) {
                throw (ServletException) problem;
            }
            if (problem instanceof IOException) {
                throw (IOException) problem;
            }
            sendProcessingError(problem, response);
        }
    }

    /**
     * Return the filter configuration object for this filter.
     */
    public FilterConfig getFilterConfig() {
        return (this.filterConfig);
    }

    /**
     * Set the filter configuration object for this filter.
     *
     * @param filterConfig The filter configuration object
     */
    public void setFilterConfig(FilterConfig filterConfig) {
        this.filterConfig = filterConfig;
    }

    /**
     * Destroy method for this filter
     */
    public void destroy() {        
    }

    /**
     * Init method for this filter
     */
    public void init(FilterConfig filterConfig) {        
        this.filterConfig = filterConfig;
        if (filterConfig != null) {
            if (debug) {                
                log("FileFilter:Initializing filter");
            }
        }
    }

    /**
     * Return a String representation of this object.
     */
    @Override
    public String toString() {
        if (filterConfig == null) {
            return ("FileFilter()");
        }
        StringBuffer sb = new StringBuffer("FileFilter(");
        sb.append(filterConfig);
        sb.append(")");
        return (sb.toString());
    }
    
    private void sendProcessingError(Throwable t, ServletResponse response) {
        String stackTrace = getStackTrace(t);        
        
        if (stackTrace != null && !stackTrace.equals("")) {
            try {
                response.setContentType("text/html");
                PrintStream ps = new PrintStream(response.getOutputStream());
                PrintWriter pw = new PrintWriter(ps);                
                pw.print("<html>\n<head>\n<title>Error</title>\n</head>\n<body>\n"); //NOI18N

                // PENDING! Localize this for next official release
                pw.print("<h1>The resource did not process correctly</h1>\n<pre>\n");                
                pw.print(stackTrace);                
                pw.print("</pre></body>\n</html>"); //NOI18N
                pw.close();
                ps.close();
                response.getOutputStream().close();
            } catch (Exception ex) {
            }
        } else {
            try {
                PrintStream ps = new PrintStream(response.getOutputStream());
                t.printStackTrace(ps);
                ps.close();
                response.getOutputStream().close();
            } catch (Exception ex) {
            }
        }
    }
    
    public static String getStackTrace(Throwable t) {
        String stackTrace = null;
        try {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            t.printStackTrace(pw);
            pw.close();
            sw.close();
            stackTrace = sw.getBuffer().toString();
        } catch (Exception ex) {
        }
        return stackTrace;
    }
    
    public void log(String msg) {
        filterConfig.getServletContext().log(msg);        
    }
    
}
