it('1851 - WEB - Settings - Web Alert Preferences - Edit Mobile Alerts / Save no email ', function(){
    Settings.menuLinkSettings();
    Settings.clickWebAlertPreferences();
    Settings_WebAlertPref.clickMobileAlertstab();
    Settings_WebAlertPref.clickInsuredEmailAddress();
    Settings_WebAlertPref.clickInsuredAddress();
    Settings_WebAlertPref.clickUserAddition();
    Settings_WebAlertPref.clickAccountNote();
    Settings_WebAlertPref.clickPremiumFinance();
    Settings_WebAlertPref.clickEmailMessage();
    Settings_WebAlertPref.clickSaveChangesMobile();
    Settings_WebAlertPref.invalidEmail();
    Settings_WebAlertPref.clickHome();
});

