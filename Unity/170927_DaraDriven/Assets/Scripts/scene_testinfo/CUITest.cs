using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;
using UnityEngine.UI;

public class CUITest : MonoBehaviour {

    public Text mpTxtString = null;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    public void OnClickBtnFromJson()
    {
        string tJson = @"
            {
            ""mName"": ""폭풍류"",
				""mStringList"": 

                [
        			""weapon_0"",
        			""weapon_777""
    			],
    			""mLevel"": 10,
				""mExp"":12345
			}
		";

        CRyuTestInfo tInfo = JsonUtility.FromJson<CRyuTestInfo>(tJson);

        Debug.Log(tInfo.mName);
        Debug.Log(tInfo.mLevel);
        Debug.Log(tInfo.mExp);

        foreach (var tElement in tInfo.mSTringList)
        {
            Debug.Log(tElement);
        }
        
    }

     public void OnClickBtnToJson()
    {
        CRyuTestInfo tInfo = new CRyuTestInfo();
        tInfo.mName = "Alberto";
        tInfo.mLevel = 999;
        tInfo.mExp = 12345;

        tInfo.mSTringList = new List<string>();
        tInfo.mSTringList.Add("weapon_777");
        tInfo.mSTringList.Add("weapon_888");

        string tJson = "";
        tJson = JsonUtility.ToJson(tInfo);

        Debug.Log("<color='red>" + tJson + "</color>");


    }

    public void OnClickBtnFromJsonOverWrite()
    {
        string tJson = @"
			{
    			""mName"": ""폭풍류"",
				""mStringList"": 
				[
        			""weapon_0"",
        			""weapon_777""
    			],
    			""mLevel"": 10,
				""mExp"":12345
			}
		";

        CRyuTestInfo tInfo = JsonUtility.FromJson<CRyuTestInfo>(tJson);

        Debug.Log(tInfo.mName);
        Debug.Log(tInfo.mLevel);
        Debug.Log(tInfo.mExp);

        foreach(var tElement in tInfo.mSTringList)
        {
            Debug.Log(tElement);
        }

        Debug.Log("--------------------");

        string tJson_0 = @"
			{
    			""mName"": ""알베르토"",
				""mLevel"": 789,
				""mExp"":5353535,
				""mStringList"": 
				[
        			""weapon_999"",
        			""weapon_123""
    			]
			}
		";

        JsonUtility.FromJsonOverwrite(tJson_0, tInfo);


        Debug.Log(tInfo.mName);
        Debug.Log(tInfo.mLevel);
        Debug.Log(tInfo.mExp);

        foreach (var tElement in tInfo.mSTringList)
        {
            Debug.Log(tElement);
        }

    }
    
}
