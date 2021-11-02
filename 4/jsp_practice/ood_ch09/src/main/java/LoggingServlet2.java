

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.apache.log4j.Level;
import org.apache.log4j.Logger;
/**
 *
 * @author yejin
 */
@WebServlet(urlPatterns = {"/ch09/logging2.do"})
public class LoggingServlet2 extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    
     static Logger log = Logger.getLogger(LoggingServlet2.class);
     
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        request.setCharacterEncoding("UTF-8");
        String name = request.getParameter("name");
        int age = Integer.parseInt(request.getParameter("age"));
        
        try{
            
              log.setLevel(Level.TRACE);
              log.info( new Date() + ":User input : name =" + name + ",age =" + age);

              log.fatal("fatal logging is possible");
              log.error(" error logging is possible");
              log.trace("trace logging is possible");
              log.warn("warn logging is possible");
              log.debug("debug van be used");

              System.out.println("system,out.println을 사용하여 로깅 정보를 출력합니다.");

              out.println("<html>");
              out.println("<head>");
              out.println("<title> Servlet loggingServlet </title>");
              out.println("<body>");
              out.println("이름 = " +  request.getParameter("name") +" <br/>");
              out.println("나이 =" + request.getParameter("age") + "<br/>");
              out.println("입력한 내용이 제대로 보이나요? 그렇다면 로깅 정보를 찾아보세요");
              out.println("</body>");
              out.println("</html>");

        }  finally{
           out.close();
       }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
