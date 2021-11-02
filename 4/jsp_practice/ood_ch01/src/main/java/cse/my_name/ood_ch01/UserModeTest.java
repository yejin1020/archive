/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cse.my_name.ood_ch01;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author yejin
 */
public class UserModeTest extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            String mode = request.getParameter("mode");
           if( mode != null ) {
                if( mode.equals("manager")){
                    showManagerModeContent(out);
                }else if ( mode.equals("user")){
                    showUserModeContent(out);    
                }else{
                    showUnknownUserModeContent(out);
                }
            } else{
                showNoModeContent(out);
            }
        }
    }
    
    private void showUserModeContent(PrintWriter out){
        out.println("<html>");
        out.println("<head>");
        out.println("<title> 일반 사용자 모드 화면</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h1> 당신은 일반 사용자입니다. </h1>");
        out.println("</body>");
        out.println("</html>");
    }
    
     private void showManagerModeContent(PrintWriter out){
        out.println("<html>");
        out.println("<head>");
        out.println("<title> 관리자 모드 화면</title>");
        out.println("</head>");
        out.println("<body>");
        out.println("<h1> 당신은 관리자입니다. </h1>");
        out.println("</body>");
        out.println("</html>");
    }
    
    private void showUnknownUserModeContent(PrintWriter out){
          out.println("<html>");
          out.println("<head>");
          out.println("<title> Unknown User 모드 화면</title>");
          out.println("</head>");
          out.println("<body>");
          out.println("<h1> 당신의 모드는 알려져있지 않습니다. </h1>");
          out.println("</body>");
          out.println("</html>");
      }
     private void showNoModeContent(PrintWriter out){
          out.println("<html>");
          out.println("<head>");
          out.println("<title> 모드 없음 화면</title>");
          out.println("</head>");
          out.println("<body>");
          out.println("<h1>  mode  파라미터가 없습니다. </h1>");
          out.println("<strong> 사용법 </strong> <br>");
          out.println("http://localhost:8084/ood_ch01?mode=[manager | user]");
          out.print("</body>");
          out.print("</html>");
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
