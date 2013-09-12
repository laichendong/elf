/**
 * User: laichendong
 * Date: 13-9-10
 * Time: 上午9:15
 */
(function ($) {
    //插件方法
    $.fn.elfPagination = function (options) {
        var opts = $.extend({}, $.fn.elfPagination.defaults, options);
        return this.each(function () {
            var container = $(this);
            var o = $.metadata ? $.extend({}, opts, container.metadata()) : opts;
            if (o.totalPage <= 0) {
                throw new Error("非法的参数值:totalPage=" + o.totalPage + "，totalPage应该为正整数。")
            }
            var status = {
                totalPage: o.totalPage,
                currPage: o.index
            };
            // 初始化到当前页
            render(o.index);
            // 事件处理
            container
                .delegate(".page", "click",function () { // 点击页码
                    if ($(this).hasClass("curr")) {
                        return;
                    }
                    goToPage($(this).attr("page"));

                }).delegate(".pre,.next", "click",function () { // 点击“上一页”“下一页”
                    if ($(this).hasClass("disabled")) {
                        return;
                    }

                    var curr = container.find(".curr");
                    if ($(this).hasClass("pre")) {
                        if (curr.hasClass("first")) {
                            return;
                        }
                        goToPage(--status.currPage);
                    } else if ($(this).hasClass("next")) {
                        if (curr.hasClass("last")) {
                            return;
                        }
                        goToPage(++status.currPage);
                    }

                }).delegate(".go", "click", function () { // 点击“确定”去某一页
                    var goToInput = container.find(".go-to");
                    var page = parseInt(goToInput.val());
                    if (isNaN(page) || !page || page < 1 || page > o.totalPage) {
                        goToInput.val(status.currPage);
                        return false;
                    } else {
                        return goToPage(page);
                    }
                });

            /**
             * 跳转到某一页
             * @param page 要跳转到的页
             * @returns {*}
             */
            function goToPage(page) {
                if (page < 1 || page > o.totalPage) {
                    return;
                } else {
                    status.currPage = page;
                    render(page);
                    // 执行回调
                    o.paged(page);
                }
            }

            /**
             * 渲染分页条
             */
            function render(currPage) {
                currPage = parseInt(currPage);
                container.empty();
                // 上一页
                if (o.showPrevAndNext) {
                    container.append('<a href="javascript:void(0)" class="pre ' + (currPage == 1 ? "disabled" : "") + '">&nbsp;</a>');
                }
                // 页码
                var isEdge, isSibling, isCurr, first, last, ellipse, ellipseAppended = false;
                for (var page = 1; page <= o.totalPage; page++) {
                    first = (page == 1 ? "first" : "");
                    last = (page == o.totalPage ? "last" : "");
                    isEdge = (page <= o.numEdge) || (page >= o.totalPage - o.numEdge + 1);
                    isSibling = (page >= currPage - o.numSiblings && page < currPage) || (page > currPage && page <= currPage + o.numSiblings);
                    isCurr = page == currPage;
                    ellipse = (page > o.numEdge && page < currPage - o.numSiblings) || (page > currPage + o.numSiblings && page < o.totalPage - o.numEdge);

                    if (isEdge || isSibling || isCurr) {
                        container.append('<a href="javascript:void(0)" class="page ' + first + ' ' + last + ' ' + (isCurr ? "curr" : "") + '" page="' + page + '">' + page + '</a>');
                    } else {
                        if (ellipse && !ellipseAppended) {
                            container.append('<span>...</span>');
                            ellipseAppended = true;
                        }
                    }
                    if (isSibling || isCurr) {
                        ellipseAppended = false;
                    }
                }
                // 下一页
                if (o.showPrevAndNext) {
                    container.append('<a href="javascript:void(0)" class="next ' + (currPage == o.totalPage ? "disabled" : "") + '">&nbsp;</a>');
                }
                // 总页数
                if (o.totalPage) {
                    container.append('<span>共' + o.totalPage + '页</span>');
                }
                // 跳页功能
                if (o.showGoTo) {
                    container.append('<label><span>到</span><input type="text" class="go-to" value="' + currPage + '"><span>页</span></label>' +
                        '<input type="button" class="go" value="确定">');
                }
            }
        });
    };

    /**
     * 默认配置
     * @type {{}}
     */
    $.fn.elfPagination.defaults = {
        totalPage: 20 // 必选参数， 总页数
        , index: 1 // 当前页
        , numEdge: 1 // 两头分别显示的页码数（前N页和倒数N页）
        , numSiblings: 3 // 当前页两边分别显示的页码数
        , showPrevAndNext: true // 上一页和下一页功能
        , showGoTo: true  // 跳转到某一页
        , showTotalPage: true // 是否显示总页数
        , paged: function (page) { // 切换到某一页后的回调
        }
    }

})(jQuery);