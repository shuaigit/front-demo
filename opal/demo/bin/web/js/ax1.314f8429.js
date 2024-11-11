"use strict";(self["webpackChunkwebapp"]=self["webpackChunkwebapp"]||[]).push([[726],{746:function(t,e,A){A.r(e),A.d(e,{default:function(){return B}});var o=function(){var t=this,e=t._self._c;return e("div",{staticClass:"home"},[e("el-container",{staticClass:"home-container"},[e("el-header",[e("div",{staticClass:"header_logo"},[e("img",{attrs:{alt:"logo",src:A(6949)}})]),e("div",{staticClass:"header_ver"},[e("span",[t._v(t._s(t.appName)+" SDK: "+t._s(t.sdkVersion))])]),e("div",[e("el-divider",{attrs:{direction:"vertical"}})],1),e("div",{staticClass:"header_nav"},[e("el-menu",{attrs:{router:"","default-active":t.activePath,mode:"horizontal","background-color":"#4c4c4c","text-color":"#fff","active-text-color":"#fff"},on:{select:t.handleSelect}},[e("el-menu-item",{staticStyle:{height:"50px","line-height":"50px"},attrs:{index:"/preview"},on:{click:function(e){return t.saveNavState("/preview")}}},[t._v("预览")]),e("el-menu-item",{staticStyle:{height:"50px","line-height":"50px"},attrs:{index:"/setting",disabled:!t.enable_setting},on:{click:function(e){return t.saveNavState("/setting")}}},[t._v("配置")])],1)],1),e("div",{staticClass:"header_right",attrs:{align:"right"}},[e("el-select",{staticClass:"mode-select",staticStyle:{width:"150px"},attrs:{size:"mini"},model:{value:t.mode_option_data,callback:function(e){t.mode_option_data=e},expression:"mode_option_data"}},t._l(t.mode_options,(function(t){return e("el-option",{key:t.value,attrs:{label:t.label,value:t.value}})})),1),e("i",{staticClass:"el-icon-s-custom"}),e("span",[t._v("admin")]),e("el-tooltip",{attrs:{effect:"dark",content:"退出登录",placement:"bottom-end",enterable:!1}},[e("el-button",{attrs:{type:"text",icon:"el-icon-switch-button"},on:{click:t.logout}})],1)],1)]),e("el-main",{staticClass:"main-container"},[e("router-view",{attrs:{mode_option:t.mode_option_data,preview_sns_mode:t.sns_mode}})],1)],1)],1)},s=[],a=(A(7658),{data(){return{appName:"--",appVersion:"--",sdkVersion:"--",activePath:"/preview",mode_options:[{label:"普通模式",value:"normal"},{label:"智能模式",value:"ai"}],timerState:void 0,enable_setting:!0,mode_option_data:"ai",sns_mode:parseInt(window.sessionStorage.getItem("snsMode")),isForceStop:!1}},created(){var t=window.sessionStorage.getItem("reloadFlag");if("true"==t)return window.sessionStorage.setItem("reloadFlag","false"),void window.location.reload(!0);console.log("home created ++");var e=window.location.href;e=e.substring(0,e.indexOf("8088/")+5)+"action",this.$http.defaults.baseURL=e,this.getInfo();var A=window.sessionStorage.getItem("homeActivePath");A&&(this.activePath=A),console.log("home:",this.activePath),this.$router.path!==this.activePath&&this.$router.push(this.activePath),this.isForceStop=!1,this.startRecvEvents(),console.log("home created --")},methods:{async getInfo(){try{const{data:t}=await this.$http.get("setting/system");console.log("home page, system get return: ",t),200===t.meta.status&&(this.appName=t.data.appName,this.appVersion=t.data.appVersion,this.sdkVersion=t.data.sdkVersion)}catch(t){this.$message.error("获取信息失败")}},handleSelect(t,e){console.log(t,e)},logout(){window.sessionStorage.clear(),this.isForceStop=!0,this.stopRecvEvents(),this.$router.push("/login")},saveNavState(t){clearTimeout(this.timerState),"/preview"===t&&(this.enable_setting=!1,this.timerState=setTimeout((()=>{this.enable_setting=!0}),1e3)),window.sessionStorage.setItem("homeActivePath",t)},startRecvEvents(){console.log("[home] startRecvEvents ++"),this.isForceStop=!0,this.stopRecvEvents(),this.isForceStop=!1;const t=window.sessionStorage.getItem("token");if(t){var e="ws://"+window.location.host+"/ws/events?token="+t,A="binary";this.wsEvents=new WebSocket(e,A),this.wsEvents.onopen=()=>{console.log("[home] ws events connected"),this.createEventstimer()},this.wsEvents.onclose=t=>{console.log("[home] ws events disconnected",t),this.isForceStop||setTimeout((()=>{this.startRecvEvents()}),2e3)},this.wsEvents.onmessage=t=>{if("string"===typeof t.data);else try{let e=new FileReader;e.onload=t=>{if(t.target.readyState===FileReader.DONE){console.log("[home] got a event: "+t.target.result);for(var e=JSON.parse(t.target.result),A=0;A<e.events.length;A++)4===e.events[A].type&&this.logout()}},e.readAsText(t.data)}catch(e){console.log("[home] ws events catch except: "+e)}},this.wsEvents.onerror=t=>{console.log("[home] ws events occure error",t)},console.log("[home] startRecvEvents --")}},stopRecvEvents(){console.log("[home] stopRecvEvents ++"),this.clearEventstimer(),this.wsEvents&&(this.wsEvents.close(),this.wsEvents=null),console.log("[home] stopRecvEvents --")},createEventstimer(){this.clearEventstimer(),this.timerEvents=setInterval((()=>{this.wsEvents&&this.wsEvents.readyState===WebSocket.OPEN&&this.wsEvents.send("keep-alive")}),3e3)},clearEventstimer(){this.timerEvents&&(clearInterval(this.timerEvents),this.timerEvents=void 0)}}}),i=a,g=A(1001),n=(0,g.Z)(i,o,s,!1,null,"437a9766",null),B=n.exports},6949:function(t){t.exports="data:image/png;base64,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"}}]);