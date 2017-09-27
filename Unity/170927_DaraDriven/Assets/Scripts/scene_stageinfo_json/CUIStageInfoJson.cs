using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;
using UnityEngine.UI;

public class CUIStageInfoJson : MonoBehaviour {

    public Text mpTxtString = null;

	// Use this for initialization
	void Start () {
		
	}

    public static string LoadResourceTextfile (string tFileName)
    {
        TextAsset tTextAsset = null;
        tTextAsset = Resources.Load<TextAsset>(tFileName);

        if(null ==tTextAsset)
        {
            return "";

        }

        return tTextAsset.text;
    }
	
	// Update is called once per frame
	void Update () {
		
	}


    public void OnClickBtnFromFile()
    {
        string tJsonStageInfoList = LoadResourceTextfile("stage_info_json");

        CStageInfoList tInfoList = JsonUtility.FromJson<CStageInfoList>(tJsonStageInfoList);

        Debug.Log("stage_info count : " + tInfoList.stage_info.Count.ToString());

        foreach(var tElement in tInfoList.stage_info)
        {
            Debug.Log("stage_info.id: " + tElement.id);
            Debug.Log("stage_info.total_enemy_count: " + tElement.total_enemy_count);

            foreach(var tElement_0 in tElement.unit_info)
            {

                Debug.Log("unity_info.x: " + tElement_0.x);
                Debug.Log("unity_info.y: " + tElement_0.y);
            }
        }

        mpTxtString.text = tJsonStageInfoList;

    }
    







}
