using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.Text;

public class FloodFill : MonoBehaviour
{
    int tRow = 0;
    int tCol = 0;
    int[,] tArray = new int[11, 11];

    Stack<int> tStack = new Stack<int>();
    StringBuilder tStringBuilder = new StringBuilder();

    // Use this for initialization
    void Start()
    {
        this.ClearGrid();

        this.DoFloodFill(5, 5);

        this.BuildGrid();

    }

    // Update is called once per frame
    void Update()
    {

    }

    public void ClearGrid()
    {
        Debug.Log("@ Create Array");

        for (tRow = 0; tRow < tArray.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tArray.GetLength(1); tCol++)
            {
                tArray[tRow, tCol] = 0;
            }
        }

        for (int ti = 0; ti < tArray.GetLength(0); ti++)
        {
            tArray[0, ti] = 2;
            tArray[tArray.GetLength(0) - 1, ti] = 2;
        }

        for (int ti = 0; ti < tArray.GetLength(1); ti++)
        {
            tArray[ti, 0] = 2;
            tArray[ti, tArray.GetLength(1) - 1] = 2;

        }
    }
    public void BuildGrid()
    {       

        int ti = 0;

        foreach (int tTemp in tArray)
        {
            if (11 == ti)
            {
                tStringBuilder.AppendLine();
                ti = 0;
            }
            tStringBuilder.Append(tTemp);
            ti++;
        }


        /*
        for (tRow = 0; tRow < tArray.GetLength(0); tRow++)
        {
            for (tCol = 0; tCol < tArray.GetLength(1); tCol++)
            {
                tStringBuilder.Append(tArray[tRow, tCol]);
            }
            //tStringBuilder.Append("\n");
            tStringBuilder.AppendLine();
        }
        */
        Debug.Log(tStringBuilder);
        tStringBuilder.Remove(0, tStringBuilder.Length);
    }

    public void DoFloodFill(int tRow, int tCol)
    {
         //count => stack에 몇개가 들어있는지
        while (0 != tStack.Count)
        {
            tStack.Pop();
        }

        tStack.Push(tCol);
        tStack.Push(tRow);

        while (0 != tStack.Count)
        {
            tRow = tStack.Pop();
            tCol = tStack.Pop();

            if (1 == tArray[tRow, tCol] || 2 == tArray[tRow, tCol])
            {
                continue;
            }

            tArray[tRow, tCol] = 1;

            tStack.Push(tCol - 1);
            tStack.Push(tRow);

            tStack.Push(tCol + 1);
            tStack.Push(tRow);

            tStack.Push(tCol);
            tStack.Push(tRow - 1);

            tStack.Push(tCol);
            tStack.Push(tRow + 1);

            this.BuildGrid();

        }

    }

}
