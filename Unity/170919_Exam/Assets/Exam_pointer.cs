using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*

	created by pokpoongryu


	C#에서 포인터를 사용할 수 있다.
	다음 두 가지 전제가 있어야만 한다. 

	1. unsafe 키워드를 표시한 코드블록안에서만 가능하다.

	2. /unsafe 옵션을 지정하여 컴파일하여야 한다. 

		mcs.rsp 파일을 만들고 -unsafe를 적어주고 Assets폴더에 위치시켜야 한다.
	unsafe
	
		형식이나 형식의 멤버 또는 문장 블록에 unsafe키워드를 붙이면 
		해당 범위 안에서는 포인터 형식을 이용해서 메모리에 대해 
        C++스타일의 포인터 연산을 수행할 수 있다. 

		unsafe code는 그에 상응하는 safe구현보다 빠르게 실행된다. 
		unsafe 하게 C#메서드를 call하는 것은 외부C함수를 call하는 것보다 빠를 수도 있다.
        왜냐하면, managed 실행환경을 벗어나는데 관련된 추가부담이 없기 때문이다. 
        
*/

public class Exam_pointer : MonoBehaviour
{

    // Use this for initialization
    void Start()
    {

        int[,] tBitmap = new int[48, 48];
        Debug.Log("@@==Bitmap");
        int tRow = 0;
        int tCol = 0;
        for (tRow = 0; tRow < tBitmap.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tBitmap.GetLength(1); tCol++)
            {
                Debug.Log(tBitmap[tRow, tCol]);
            }
        }

        #region FUNCTION_USE_POINTER
        BlueFilter(tBitmap);
        #endregion

        Debug.Log("@@==tBitmap BlueFilter");
        for (tRow = 0; tRow < tBitmap.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tBitmap.GetLength(1); tCol++)
            {
                Debug.Log(tBitmap[tRow, tCol]);
            }
        }
    }

    // Update is called once per frame
    void Update()
    {

    }

    unsafe void BlueFilter(int[,] tBitmap)
    {
        int tLength = tBitmap.Length;

        //fixed구문은 managed객체를 고정한다.
        //이것이 필요한 이유는 
        //C#에서는 메모리 단편화 등이 가비지컬렉터에 의해 관리되는 메커니즘 때문에 
        //메모리 등이 자동으로 위치이동하게 되고 ( 단편화된 메모리를 정리한다는 얘기이다. )
        //포인터가 가리키고 있는 힙 메모리가 유효하지 않게 될 수도 있기 때문이다.
        
        fixed (int *tpB = tBitmap)
            {
                int* tpPtr = tpB;
                for(int ti =0; ti<tLength; ti++)
                {
                    *tpPtr++ &= 0xFF;
                }
            }
        
    }


}
