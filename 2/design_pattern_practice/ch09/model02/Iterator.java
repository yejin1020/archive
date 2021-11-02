
package deu.cse.design_pattern.ch09.model02;

public interface Iterator <T> {
    // 다음 값이 있는지 확인
   boolean hasNext() ;

   T next() ;

}
