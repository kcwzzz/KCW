using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class CUnit
{
    public int mX = 0;
    public int mY = 0;

    public void Do()
    {
        Debug.Log("CUnit.Do");
    }

}

public class CActor:CUnit
{
    public void DoDo()
    {
        base.Do();
        Debug.Log("Cactor.DoDo");
    }
}

public class CExam_5 : MonoBehaviour {

    decimal mCurrentPrice;

    public decimal _currentPrice
    {
        get { return mCurrentPrice; }
        set { mCurrentPrice = value; }
    }
  
	// Use this for initialization
	void Start () {
        _currentPrice = 3;
        Debug.Log(_currentPrice.ToString());

        CActor tActor;
        tActor = new CActor();

        tActor.DoDo();
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
