#elf pagination#

##示例调用##
1. 引入脚本
    `<script src="../lib/jquery.min.js"></script>
     <script src="../lib/jquery.metadata.js"></script>`
2. html
    `<div class="elfPagination { totalPage: 10}"></div>`
3. 脚本
    `$(".elfPagination").elfPagination();`

##选项##
<table>
<tr><td>名称</td><td>类型</td><td>默认值</td><td>描述</td></tr>
<tr><td>totalPage</td><td>number</td><td>10</td><td>必选，总页数</td></tr>
<tr><td>index</td><td>number</td><td>1</td><td>当前页</td></tr>
<tr><td>numEdge</td><td>number</td><td>1</td><td>页码条两端固定显示的页码数</td></tr>
<tr><td>numSiblings</td><td>number</td><td>3</td><td>当前页左右两侧固定显示的页码数</td></tr>
<tr><td>showPrevAndNext</td><td>boolean</td><td>true</td><td>是否显示“上一页”和“下一页”按钮</td></tr>
<tr><td>showGoTo</td><td>boolean</td><td>true</td><td>是否显示“跳转到某页”</td></tr>
<tr><td>showTotalPage</td><td>boolean</td><td>true</td><td>是否显示“总页数”</td></tr>
<tr><td>paged</td><td>function</td><td>function(page){}</td><td>切换到某一页后的回调函数，参数page为切换到的页码</td></tr>
</table>