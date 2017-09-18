using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CTestArray : MonoBehaviour
{
    // Use this for initialization
    void Start()
    {

        Debug.Log("@rectangular array");
        int tRow = 0;
        int tCol = 0;

        int[,] tArray = new int[10, 10];

        for (tRow = 0; tRow < tArray.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tArray.GetLength(1); tCol++)
            {
                tArray[tRow, tCol] = tRow * 10 + tCol;
            }
        }

        for (tRow = 0; tRow < tArray.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tArray.GetLength(1); tCol++)
            {
                Debug.Log(tArray[tRow, tCol].ToString());
            }
        }        
    }
    // Update is called once per frame
    void Update()
    {

    }
}
