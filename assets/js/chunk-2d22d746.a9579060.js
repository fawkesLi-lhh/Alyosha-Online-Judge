(window["webpackJsonp"]=window["webpackJsonp"]||[]).push([["chunk-2d22d746"],{f820:function(t,e,a){"use strict";a.r(e);var l=function(){var t=this,e=t.$createElement,a=t._self._c||e;return a("div",[[a("el-table",{staticStyle:{width:"100%"},attrs:{data:t.tableData,stripe:""}},[a("el-table-column",{attrs:{prop:"id",label:"id",width:"180"}}),a("el-table-column",{attrs:{prop:"Title",label:"Title"},scopedSlots:t._u([{key:"default",fn:function(e){return[a("router-link",{attrs:{to:"/detail/"+e.row.Title}},[t._v(t._s(e.row.Title))])]}}])}),a("el-table-column",{attrs:{prop:"Ratio",label:"Ratio",width:"180"}}),a("el-table-column",{attrs:{prop:"Date",label:"Date",width:"180"}})],1)]],2)},n=[],i={name:"",data:function(){return{tableData:[]}},methods:{},created:function(){var t=this;this.$http.get("/issues.json").then((function(e){t.tableData=e.data}))}},o=i,r=a("2877"),s=Object(r["a"])(o,l,n,!1,null,"c6f24276",null);e["default"]=s.exports}}]);
//# sourceMappingURL=chunk-2d22d746.a9579060.js.map